#!/bin/bash
#  This file installs the configuration files for Blissymbolics
#  for applications like LaTeX and Lyx as well as the fonts
#  into the correct locations to serve up the operating system.
#  It is designed to be instaled into a Debian based system.
#
# This file must be run as root (or use sudo)
# from the blissymbolics (i.e. parent of this ./system/
# directory)

# Create the binary locale file and install it
mkdir -p /usr/local/share/i18n/locales/
cp src/locales/aus_AU /usr/share/i18n/locales/aus_AU
cp src/locales/aus_AU /usr/local/share/i18n/locales/aus_AU
# cd /usr/local/share/i18n/locales/
localedef -i aus_AU -f UTF-8 aus_AU.UTF-8 -c -v
# Ensure there is a reference to it in the /etc/locale.gen file
# of the form aus_AU.UTF-8 UTF-8 (using SED)
if grep -q -wi "aus_AU.UTF-8" /etc/locale.gen; then
   echo "aus_AU.UTF-8 already specified, so just re-encoding."
else
   sed -i '59iaus_AU.UTF-8 UTF-8' /etc/locale.gen
fi
# Set up Debian locales again now
locale-gen
# Run a test
LANG=aus_AU.UTF-8 date

# Install the Blissymbolics True Type and Open Type font
mkdir -p /usr/local/share/texmf/fonts/truetype/
cp src/fonts/Blissymbolics-Courier.ttf /usr/local/share/texmf/fonts/truetype/
mkdir -p /usr/local/share/texmf/fonts/opentype/
cp src/fonts/Blissymbolics-Courier.otf /usr/local/share/texmf/fonts/opentype/
mkdir -p /usr/local/share/fonts
cp src/fonts/Blissymbolics-Courier.otf /usr/local/share/fonts/
/usr/bin/fc-cache
dpkg-reconfigure -u fontconfig-config

# Set up LaTeX
# Set up the local directory
cp src/latex/01local.cnf /etc/texmf/texmf.d/
# copy in the Blissymbolics style sheets
mkdir -p /usr/share/texmf/tex/latex/bliss/
cp src/latex/bliss_article.* /usr/local/share/texmf/
cp src/latex/size??.clo /usr/local/share/texmf/
cp src/latex/bliss_article.* /usr/share/texmf/tex/latex/bliss/
cp src/latex/size??.clo /usr/share/texmf/tex/latex/bliss/
# set up babel for Blissymbolics
mkdir -p /usr/local/share/texmf/source/latex/babel/
cp src/latex/blissymbolics.dtx /usr/local/share/texmf/source/latex/babel/
cp src/latex/blissymbolics.ins /usr/local/share/texmf/source/latex/babel/
WKDIR=$(pwd)
cd /usr/local/share/texmf/source/latex/babel/
xetex blissymbolics.ins
cd ${WKDIR}
mkdir -p /usr/share/texlive/texmf-dist/tex/generic/babel-blissymbolics/
cp /usr/local/share/texmf/source/latex/babel/blissymbolics.ldf /usr/share/texlive/texmf-dist/tex/generic/babel-blissymbolics/
cp src/latex/blissymbolics.sty /usr/share/texlive/texmf-dist/tex/generic/babel/
cp src/latex/hyph-aus-bliss.hyp.txt /usr/share/texlive/texmf-dist/tex/generic/hyph-utf8/patterns/txt/
cp src/latex/hyph-aus-bliss.pat.txt /usr/share/texlive/texmf-dist/tex/generic/hyph-utf8/patterns/txt/
mkdir -p /usr/share/texlive/texmf-dist/tex/generic/babel/locale/aus
cp src/latex/babel-aus-bliss.ini /usr/share/texlive/texmf-dist/tex/generic/babel/locale/aus/
# copy in the Blissymbolics date and time format
mkdir -p /usr/share/texlive/texmf-dist/tex/latex/datetime2-blissymbolics
cp src/latex/datetime2-blissymbolics*.ldf /usr/share/texlive/texmf-dist/tex/latex/datetime2-blissymbolics/
# Set up the Blissymbolics language for LaTeX
cp src/latex/loadhyph-aus-bliss.tex /usr/share/texlive/texmf-dist/tex/generic/hyph-utf8/loadhyph/
cp src/latex/hyph-aus-bliss.tex /usr/share/texlive/texmf-dist/tex/generic/hyph-utf8/patterns/tex/
# Ensure the Blissymbolics language is loaded into /var/lib/texmf/tex/generic/config/language.def
# and into /var/lib/texmf/tex/generic/config/language.dat
if ! grep -e "blissymbolics" /var/lib/texmf/tex/generic/config/language.def ; then
  sed  -i '32i \\\addlanguage{blissymbolics}{loadhyph-aus-bliss.tex}{}{5}{5}' /var/lib/texmf/tex/generic/config/language.def
fi
if ! grep -e "blissymbolics" /var/lib/texmf/tex/generic/config/language.dat ; then
cat >>/var/lib/texmf/tex/generic/config/language.dat <<EOF
blissymbolics loadhyph-aus-bliss.tex
=semantography
=australian
EOF
fi
# TrackLang complains about there being no Blissymbolics language.
# However, the following seems to not help, so commented it out.
# # Update tracklang
# if ! grep -e "blissymbolics" /usr/share/texlive/texmf-dist/tex/generic/tracklang/tracklang.tex ; then
#   sed  -i '1937i \\\TrackLangDeclareDialectOption{blissymbolcs}{blissymbolics}{AU}{}{}{}{}' /usr/share/texlive/texmf-dist/tex/generic/tracklang/tracklang.tex
#   sed  -i '2113i \\\LetTrackLangOption{aus-AU}{blissymbolics}' /usr/share/texlive/texmf-dist/tex/generic/tracklang/tracklang.tex
# fi
# Copy over the configuration file
cp src/latex/texlive-lang-blissymbolics.cnf /var/lib/tex-common/hyphen-cnf/texlive/
# And load it
#mtxrun --generate
#updmap-sys
mktexlsr /var/lib/texmf
fmtutil -sys --all
# Now run texhash to update systems
texhash

# Set up R
## The following installs the showtext package.  You have to pass it
## the full path to the font(s) you want to use for each R script when
## the library is loaded.
/usr/bin/Rscript -e 'install.packages("showtext")'

# Set up LyX
mkdir -p /usr/local/share/lyx/layouts
mkdir -p /usr/local/share/lyx/ui
cp src/lyx/bliss_article.layout /usr/local/share/lyx/layouts/
cp src/lyx/bliss_class.inc /usr/local/share/lyx/layouts/
cp src/lyx/bliss.ui /usr/local/share/lyx/ui/
cp src/lyx/blisscontext.inc /usr/local/share/lyx/ui/
cp src/lyx/blissmenus.inc /usr/local/share/lyx/ui/
cp src/lyx/blisstoolbars.inc /usr/local/share/lyx/ui/
/usr/bin/lyx -batch --execute "reconfigure" src/lyx/temp.lyx
cd src/lyx
msgfmt -o aus_AU.mo aus_AU.po
cd ${WKDIR}
mkdir -p /usr/local/share/locale/aus_AU/LC_MESSAGES/
cp src/lyx/aus_AU.mo /usr/local/share/locale/aus_AU/LC_MESSAGES/lyx.mo
# To get Blissymbolics keyboard to work, ibus needs to be installed.
apt-get install ibus ibus-gtk ibus-gtk3 ibus-table ibus-clutter ibus-m17n
echo "Manual configuration to your environment required. Please run"
echo "'ibus-setup', then switch to the 'Input Method' tab, select "
echo "'Add', choose 'Other' at the bottom of the list, then choose "
echo "'t-unicode (m17n)' and select 'Add'."
echo "It is wise to then logout and reboot."
echo "This must be done for each user of this computer."

