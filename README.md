# Blissymbolics

$Date: Tue 24 Sep 2024 21:37:11 AEST$

## Description

This repository contains the main files for managing the Blissymbolics 
language, including font files and files to configure applications to use 
the Blissymbolics language on a Linux-based system.
It is based around a font set of lines and curves, which was developed 
after looking at Charles Bliss' typewriter modification design.  Unfortunately, 
developing a keyboard input for such a font is complex since, apart from some 
special fixed with space symbols, is wholly combining characters.  Previous 
approaches to developing a symbol set, not just here but elsewhere by other 
organisations, had been to use a character for each word, but there are 
potentially many thousands of words.  A simple drawing set is all that is 
required and all that Charles Bliss seems to have had in mind (see his book, 
Semantography (Blissymbolics) Second Enlarged Edition 1965, page 89).

The repository provides a language environment for the Debian Linux environment 
(it should therefore work very comfortably on a Raspberry Pi, which is essentially 
Debian-based).  It provides a LaTeX language environment that ensures dates and 
times are printed correctly and also provides translations for book writing 
sections (noting that LaTeX is a publishing environment).

A complete Blissymbolics system also assumes the installation of Cell Writer (the 
Hyper Quantum fork by Ross Summerfield) to enable text input and it assumes the 
setup of the correct fonts on any tools being used.

## Required Packages, Files and Configurations

This Blissymbolics suite requires Debian as the base product (only tested with 
Bookworm), has only been tested with the LXDE desktop and assumes LyX is installed.  

It requires and is set up for TexLive LaTeX environment for desktop publishing.  
It is known to work with the Mousepad simple text editor and also with gEdit (but 
not with gEdit's terminal emulator add-on).  

It assumes you install the Hyper Quantum fork of Michael Levin's Cell Writer.  
Michael's cellwriter does not handle combining characters, so a fork was produced 
that re-lays out the application such that it has more structure under the hood.  
As at writing this, the Hyper Quantum fork needs the recognition engine rewriting.  

Cell Writer requires both LaTeX (specifically, the XeTeX engine for handling Unicode 
fonts) and R to produce statistical reports.

A good Unicode Terminal emulator is helpful but not required.  None that I have 
experimented with terminal emulators to see if they can handle the combining 
character layout of the font used here for Blissymbolics.  But the best so far is 
the Rxvt Unicode terminal.  However, it requires some very special configuration to 
make it work with Cell Writer.  I have substantially written a simple but mostly
working multi-tabbed one.  It is now generally available on GitHub (see 
https://github.com/ross-sum/bliss_term).

## References and Links

### Tex:
- [ ] [tlmgr - TeX Live package manager](https://tug.org/texlive/tlmgr.html), which 
  is good background, but not easily run under Debian.
- [ ] [How to Create a New language](https://tex.stackexchange.com/questions/385044/how-creating-new-language-package-styles-babel-script?newreg=ae6cd7dc6acb4d5dad860e319f04fc49)
- [ ] [.sty and .cls File Placement](https://tex.stackexchange.com/questions/1137/where-do-i-place-my-own-sty-or-cls-files-to-make-them-available-to-all-my-te)
- [ ] [Date Format in yyyy-mm-dd arrangement](https://tex.stackexchange.com/questions/152392/date-format-yyyy-mm-dd)
- [ ] [Using a new language with Babel](https://davidcarlisle.github.io/uk-tex-faq/FAQ-newlang.html)
- [ ] [Using a new language with Babel](https://muzimuzhi.github.io/texfaq.github.io/FAQ-newlang)

### Unicode:
- [ ] [Unicode CLDR](https://cldr.unicode.org/) - Unicode Common Locale Data 
  Repository, including details on how to contribute

### Blissymbolics:
- [ ] [BCI Symbol Files](https://www.blissymbolics.org/index.php/symbol-files) - 
  the current BCI authorised vocabulary of Blissymbolics.

## Installation
At this point in time, installation is rather crude.  The steps are:
* Install or update to the latest Debian version.  At time of writing, this 
  was Bookworm.
* Install required Debian packages, namely TexLive and R.
- Install the package XeLaTeX viz

    sudo apt-get install texlive texlive-xetex

- Install the package R viz

    sudo apt-get install r-base r-recommended r-cran-shiny r-cran-sf

  Set the Font tuning method for screen (system default) to Autohinter
  Leave the Automatic font hinting style at the default of slight
  Leave the Enable subpixel rendering for screen at the default of Automatic
  Leave Enable subpixel rendering for screen at the default of No

* Download or unpack a clone of the repository into a directory somewhere 
  that allows root access.  You need to take care that root has access, for 
  instance, if it is a mounted drive, root may not have access.  Best option 
  is /usr/local/src/
* From the top level of the blissymbolics directory, as the user that 
  unpacked the clone of the repository, execute the commands: 
    chmod +x system/*
    chmod +x src/commands/*
* From the top level of the blissymbolics directory, as root, execute the 
  script: 

    system/install_bliss.sh

* Apply any local configurations required to installed Debian packages.
* Finally, it may be wise, but not necessary, to reboot, or at least to log 
  out and log back in again.

## Some Background on Packages and on Installation

LaTeX needs to be configured for the style sheet and the fonts. Under Debian, 
LaTeX needs to be configured for access to the /usr/local entries (so that 
upgrades are not affected). 

LyX doesn't actually recognise the LaTeX directories, so the install_bliss 
script also copies files for LaTeX into the /usr/share/texmf/tex/latex/ 
directory structure and makes other symbolic links.

R is often used by LyX for its graphical output, generating encapsulated 
postscript (.eps) files.

There are two methods of getting R to recognise a non-standard TrueType 
font. One is the extrafont package. It will load all TrueType fonts but, 
unfortunately, you cannot print using most of them (but you can display 
them). The other is the showtext package. With it, you must specify the 
font(s) that you wish to use, including their full path name, in the R 
script. 

For LyX, out of the box, it does not support input from non-keyboard 
Unicode characters.  Out of the box, the only way to get text there is 
via a copy and Paste Special (Paste from LaTeX).  It is for this reason 
that further work is required to set up LyX (see Roadmap and 
Contributing below).  LyX draws upon the system and user fonts for its 
screen fonts.  So, providing an update is done (and you may need to 
manually do a Tools|Reconfigure within LyX yourself in addition to 
that done by the script), it will recognise the Blissymbolics font.  
For a document, though, you may need to check the 'Use non-TeX fonts 
(via XeTeX/LuaTeX)' check box under the menu Document|Settings...|Fonts.

A UI file for LyX is partially written.  It is currently installed in 
/usr/local/share/lyx/ui/, but it cannot be used from there.  If you 
wish to try it out, then copy or make symolic links all the files in 
that directory to ~/.lyx/ui/ and then select it as the User interface 
file, which is located in the User Interface subsection of Look & Feel 
in Tools|Preferences.  Alternatively, you can select Blissymbolics from
the Tools|Preferences|Language Settings.  However, LyX does not have a 
mechanism built in to change its own menu font.  LyX documentation says 
to run qtconfig, but there is no such thing anymore.  Apparently qt5ct 
replaces it.  It needs to be run by each of the computer's users that 
plans to use LyX with Blissymbolics. After the system/install_bliss 
package installs it, you will need to run it (go to a terminal emulator, 
type `qt5ct`, then select the Blissymbolics-Courier font.  Once done 
and saved, log out and log in again for the font to take effect.

It is also worth noting that LyX puts a Left-to-Right Override (LRO) 
U+202D character at the beginning of every paragraph. The font file 
should have a (blank) character in this point, otherwise a rectangle 
or something similar will be displayed. 

Finally, in preparation for a Blissymbolics-friendly terminal emulator, 
symbolic links to a number of the key terminal command prompt type 
(that is, text based) commands have been prepared and loaded 
into /usr/local/bin.  They do need testing with the Blissymbolics fork 
of Cell Writer, because a number of them do use indicators.  Either the 
indicators need to be removed (but they are helpful to command 
interpretation) or just checked that Cell Writer will put them in 
exactly the same place.  Further text commands need to be translated 
and added the the symbolic links installer.  As a note, rerunning 
this installer will not be harmful to any existing symbolic links, 
but it will add any new ones.  If you wish to replace as a consequence 
of updating this, then the old ones need to be deleted.  That could 
also be done with a script.

## Support
For help, email me at ross [at] hyperquantum [dot] com [dot] au.  
Otherwise, issue tracking is through GitHub.

## Roadmap
Planned future releases include:
- Modifications to the LyX (more or less a graphical LaTeX front-end) 
  such that it will work with Cell Writer.  This work is in progress, 
  with the .po file already started on (it is a big document in its own 
  right). Cell Writer interface is much harder.  Whilst you could get 
  Cell Writer to output keystrokes and using a kmap file to translate, 
  there aren't enough keys on the keyboard - Blissymbolics has 141 
  characters, of which 6 are not combining characters (so 135 are 
  combining characters).  Unfortunately, LyX's kmap (and friends) files 
  only take a single input key stroke for any output (which can be a 
  string of characters), not the other way around.  That leaves LyX 
  code modification as the only global method (an opportunity for 
  someone who understands C++ and would like to do a little work 
  on LyX).  Locally, the installation of ibus works.  There is a 
  button on Cell Writer to output in ibus format and, while a bit slow,
   works.
- The Cell Writer fork itself is in its infancy, being barely usable 
  with a large training set, with the recognition engine needing a full 
  rewrite.
- Other work and tools to completely modify the Linux desktop to 
  present everything in Blissymbolics need to be developed.
- The font set, developed with FontForge, needs improvement.  I am 
  unsure at this stage, but proper improvement could lead to a 
  reduction in characters required in the character set (it 
  would be nice to find 1D hexadecimal characters to bring the 
  character set down to 80 hexadecimal (128 decimal) or less 
  characters.  However, a review of all words so far suggests tha a
  reduction is unlikely.  There are two fonts set up, one being 
  monospace (important for terminals and useful for number handling 
  in spreadsheets) and the other being proportional, but both are 
  the same in all other aspects.
- The Blissymbolics symbol set used here also needs to get properly 
  inserted into the Unicode set.  It currently resides in the Private 
  Use area from E100 to E18C hexadecimal.  My understanding is that 
  there needs to be a few books written in Blissymbolics before the 
  Unicode consortium will even think about it (even though there are 
  Unicode characters for Elvish, a language made up by J.R.R. Tolkien).

## Contributing
Contributions are welcome.  The following needs to be done.
- We need to get the language recognised by the Unicode Consortium.  
  This may require a few of us writing a few books and probably requires 
  a lot of lobbying.  Prior to that, we all need to agree on the 
  character set.  That may take a bit of work.
- We need to prepare Blissymbolics translations for various tools such 
  as the LibreOffice suite.
- We need to expand out the Blissymbolics translation to the Linux desktop.

To help, contact me, Ross Summerfield, ross <at> hyperquantum <dot> com <dot> au.  
Collaboration is envisaged to be through Github.

To expand out the capabilities of setting up the Blissymbolics locale, 
check out the installation script (install_bliss.sh) in the `system` 
directory as guidance on the way forward.

## Authors and acknowledgment
This work was developed by and is currently maintained by Ross Summerfield.

Blissymbolics, originally called Semantography, was developed by the late 
Dr Charles K. Bliss, a former resident of Coogee, New South Wales, Australia. 
Thanks to Charles for his tireless work in ensuring that the symbol set would 
work and was extensible to describe any thing, feeling or concept.

Thanks also to Blissymbolics Communication International (BCI), 
https://www.blissymbolics.org/index.php/symbol-files for their work in 
collating and maintaining a 'dictionary' of symbols.

## Licence
This package is licensed under the GNU Lesser General Public Licence 
(LGPL), version 3.

## Project status
An audit of the dictionary used here against the works of Dr Charles Bliss needs 
to be completed.  Fortunately, the National Library of Australia is just down the 
road, so getting access to his documentation (books and papers) is straight forward.

The font file needs to be reordered still, after the most recent loading of the 
dictionary to ensure all characters are included.  This reordering will need to 
be done in conjunction with adjusting the dictionary so that the words are correct.  
At that point, the dictionary and the font files will be ready for publishing to 
the world.

