# Blissymbolics
$Date: $

## Description

This repository contains the main files for managing the Blissymbolics language, including font files and files to configure applications to use the Blissymbolics language on a Linux-based system.
It is based around a font set of lines and curves, which was developed after looking at Charles Bliss' typewriter modification design.  Unfortunately, developing a keyboard input for such a font is complex since, apart from some special fixed with space symbols, is wholly combining characters.  Previous approachesi to developing a symbol set, not just here but elsewhere by other organisations, had been to use a character for each word, but there are potentially many thousands of words.  A simple drawing set is all that is required and all that Charles Bliss seems to have had in mind (see his book, Semantography (Blissymbolics) Second Enlarged Edition 1965, page 89).

The repository provides a language environment for the Debian Linux environment (it should therefore work very comfortably on a Raspberry Pi, which is essentially Debian-based).  It provides a LaTeX language environment that ensures dates and times are printed correctly and also provides translations for book writing sections (noting that LaTeX is a publishing environment).

A complete Blissymbolics system also assumes the installation of Cell Writer (the Hyper Quantum fork by Ross Summerfield) to enable text input and it assumes the setup of the correct fonts on any tools being used.

## Required Packages, Files and Configurations

This Blissymbolics suite requires Debian as the base product (only tested with Bookworm), has only been tested with the LXDE desktop and assumes LyX is installed.  

It requires and is set up for TexLive LaTeX environment for desktop publishing.  It is known to work with the Mousepad simple text editor and also with gEdit (but not with gEdit's terminal emulator add-on).  

It assumes you install the Hyper Quantum fork of Michael Levin's Cell Writer.  Michael's cellwriter does not handle combining characters, so a fork was produced that re-lays out the application such that it has more structure under the hood.  As at writing this, the Hyper Quantum fork needs the recognition engine rewriting.  

Cell Writer requires both LaTeX (specifically, the XeTeX engine for handling Unicode fonts) and R to produce statistical reports.

A good Unicode Terminal emulator is helpful but not required.  None that I have experimented with handle the combining character layout of the font used here for Blissymbolics.  But the best so far is the Rxvt Unicode terminal.  However, it requires some very special configuration to make it work with Cell Writer.  I intend to write a simple but working one.

## References and Links

### Tex:
- [ ] [tlmgr - TeX Live package manager][https://tug.org/texlive/tlmgr.html tlmgr], which is good background, but not easily run under Debian.
- [ ] [How to Create a New language][https://tex.stackexchange.com/questions/385044/how-creating-new-language-package-styles-babel-script?newreg=ae6cd7dc6acb4d5dad860e319f04fc49]
- [ ] [.sty and .cls File Placement][https://tex.stackexchange.com/questions/1137/where-do-i-place-my-own-sty-or-cls-files-to-make-them-available-to-all-my-te]
- [ ] [Date Format in yyyy-mm-dd arrangement][https://tex.stackexchange.com/questions/152392/date-format-yyyy-mm-dd]
- [ ] [Using a new language with Babel][https://davidcarlisle.github.io/uk-tex-faq/FAQ-newlang.html]
- [ ] [Using a new language with Babel][https://muzimuzhi.github.io/texfaq.github.io/FAQ-newlang]

### Unicode:
- [ ] [Unicode CLDR][https://cldr.unicode.org/] - Unicode Common Locale Data Repository, including details on how to contribute

### Blissymbolics:
- [ ] [BCI Symbol Files][https://www.blissymbolics.org/index.php/symbol-files] - the current BCI authorised vocabulary of Blissymbolics.

- [ ] [Set up project integrations](http://gitlab.canberra.hyperquantum.com.au/ross/blissymbolics/-/settings/integrations)

## Installation
At this point in time, installation is rather crude.  The steps are:
* Install or update to the latest Debian version.  At time of writing, this was Bookworm.
* Install required Debian packages, namely TexLive and R.
- Install the package XeLaTeX viz

    sudo apt-get install texlive-xetex

- Install the package R viz

    sudo apt-get install r-base r-recommended r-cran-shiny r-cran-sf

* Download or unpack a clone of the repository into a directory somewhere that allows root access.
* From the top level of the blissymbolics directory, as root, execute the script: 

    system/install_bliss

* Apply any local configurations required to installed Debian packages.
* Finally, it may be wise, but not necessary, to reboot, or at least to log out and log back in again.

## Some Background on Packages and on Installation

LaTeX needs to be configured for the style sheet and the fonts. Under Debian, LaTeX needs to be configured for access to the /usr/local entries (so that upgrades are not affected). 

LyX doesn't actually recognise the LaTeX directories, so the install_bliss script also copies files for LaTeX into the /usr/share/texmf/tex/latex/ directory structure.

R is often used by LyX for its graphical output, generating encapsulated postscript (.eps) files.

There are two methods of getting R to recognise a non-standard TrueType font. One is the extrafont package. It will load all TrueType fonts but, unfortunately, you cannot print using most of them (but you can display them). The other is the showtext package. With it, you must specify the font(s) that you wish to use, including their full path name, in the R script. 

For LyX, out of the box, it does not support input from non-keyboard Unicode characters.  Out of the box, the only way to get text there is via a copy and Paste Special (Paste from LaTeX).  It is for this reason that further work is required to set up LyX (see Roadmap and Contributing below).  LyX draws upon the system and user fonts for its screen fonts.  So, providing an update is done (and you may need to manually do a Tools|Reconfigure within LyX yourself in addition to that done by the script), it will recognise the Blissymbolics font.  For a document, though, you may need to check the 'Use non-TeX fonts (via XeTeX/LuaTeX)' check box under the menu Document|Settings...|Fonts.
It is also worth noting that LyX puts a Left-to-Right Override (LRO) U+202D character at the beginning of every paragraph. The font file should have a (blank) character in this point, otherwise a rectangle or something similar will be displayed. 

## Support
For help, email me at ross <at> hyperquantum <dot> com <dot> au.  Otherwise, issue tracking is through GitHub.

## Roadmap
Planned future releases include:
- Modifications to the LyX (more or less a graphical LaTeX front-end) such that it will work with Cell Writer.
- The Cell Writer fork itself is in its infancy, being barely usable with a large training set, with the recognition engine needing a full rewrite.
- Other work and tools to completely modify the Linux desktop to present everything in Blissymbolics need to be developed.
- The font set, developed with FontForge, needs improvement.  I am unsure at this stage, but proper improvement could lead to a reduction in characters required in the character set (it would be nice to find 1D hexadecimal characters to bring the character set down to 80 hexadecimal (128 decimal) or less characters.
- The Blissymbolics symbol set used here also needs to get properly inserted into the Unicode set.  It currently resides in the Private Use area from E100 to E18C hexadecimal.  My understanding is that there needs to be a few books written in Blissymbolics before the Unicode consortium will even think about it (even though there are Unicode characters for Elvish, a language made up by J.R.R. Tolkien).

## Contributing
Contributions are welcome.  The following needs to be done.
- We need to get the language recognised by the Unicode Consortium.  This may require a few of us writing a few books and probably requires a lot of lobbying.  Prior to that, we all need to agree on the character set.  That may take a bit of work.
- We need to prepare Blissymbolics translations for various tools such as the LibreOffice suite.
- We need to expand out the Blissymbolics translation to the Linux desktop.

To help, contact me, Ross Summerfield, ross <at> hyperquantum <dot> com <dot> au.  Collaboration is envisaged to be through Github.

To expand out the capabilities of setting up the Blissymbolics locale, check out the installation script (install_bliss) in the `system` directory as guidance on the way forward.

## Authors and acknowledgment
This work was developed by and is currently maintained by Ross Summerfield.

Blissymbolics, originally called Semantography, was developed by Charles K. Bliss, a former resident of Coogee, New South Wales, Australia. Thanks to Charles for his tireless work in ensuring that the symbol set would work and was extensible to describe any thing, feeling or concept.

Thanks also to Blissymbolics Communication International (BCI), https://www.blissymbolics.org/index.php/symbol-files for their work in collating and maintaining a 'dictionary' of symbols.

## Licence
This package is licensed under the GNU Lesser General Public Licence (LGPL), version 3.

## Project status
An audit of the dictionary used here against the works of Charles Bliss needs to be carried out.  Fortunately, the National Library of Australia is just down the road, so getting access to his documentation (books and papers) is straight forward.

The font file needs to be reordered still, after the most recent loading of the dictionary to ensure all characters are included.  This reordering will need to be done in conjunction with adjusting the dictionary so that the words are corect.  At that point, the dictionary and the font files will be ready for publishing to the world.

