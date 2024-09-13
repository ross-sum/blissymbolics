# -*- text -*-
# file austmenus.inc
# This file is part of LyX, the document processor.
# Licence details can be found in the file COPYING.

# author Ross Summerfield
# author Jean-Marc Lasgouttes
# author John Levon
# author Michael Gerz

# Full author contact details are available in file CREDITS.

# The interface is designed (partially) following the KDE Human Interface
# Guidelines (http://techbase.kde.org/Projects/Usability/HIG)

# Casing Rules:
# Capitalise all words in the element, with the following exceptions:
# * Articles: a, an, the.
# * Conjunctions: and, but, for, not, so, yet ...
# * Prepositions of three or fewer letters: at, for, by, in, to ...
#   (except when the preposition is part of a verb phrase, such as "Check In")
# (http://library.gnome.org/devel/hig-book/stable/design-text-labels.html.en)

Format 4

Menuset

	Menubar
# Make the first 4 menus be as much as expected as possible
		Submenu "" "file"
		Submenu "" "edit"
		Submenu "" "view"
		Submenu "" "insert"
		Submenu "" "navigate"
		Submenu "" "document"
		Submenu "" "tools"
		Submenu "" "help"
	End

#
# FILE MENU
#

	Menu "file"
		Item "" "buffer-new"
		Item "  ..." "buffer-new-template"
		Item "..." "file-open"
		Submenu " " "file_lastfiles"
		Separator
		Item "" "buffer-close"
		Item " " "buffer-close-all"
		Item "" "buffer-write"
		Item " ..." "buffer-write-as"
		Item " " "buffer-write-all"
		Item " " "buffer-reload"
		Submenu " " "file_vc"
		Separator
		Submenu "" "file_import"
		Submenu "" "file_export"
		OptItem "..." "buffer-export fax"
		Separator
		Item " " "window-new"
		Item " " "window-close"
		Separator
		Item "" "lyx-quit"
	End

	Menu "file_lastfiles"
		Lastfiles
	End

	Menu "file_vc"
		OptItem "..." "vc-register"
		OptItem " ..." "vc-check-in"
		OptItem "  " "vc-check-out"
		OptItem "" "vc-copy"
		OptItem "" "vc-rename"
		OptItem "    " "vc-repo-update"
		OptItem "   " "vc-revert"
		OptItem " 1  " "vc-undo-last"
		OptItem "   ..." "vc-compare"
		OptItem "  ..." "dialog-show vclog"
		OptItem "  " "vc-locking-toggle"
	End

	Menu "file_import"
		ImportFormats
	End

	Menu "file_export"
		ExportFormat
		Item " ..." "buffer-export-as"
		Separator
		ExportFormats
		Item "   ..." "buffer-export custom"
	End

#
# EDIT MENU
#

	Menu "edit"
		Item "" "undo"
		Item "" "redo"
		Separator
		Item "" "cut"
		Item "" "copy"
		Item "" "paste"
		Submenu " " "edit_pasterecent"
		Submenu " " "edit_paste"
		Separator
		Item "  " "inset-select-all"
		Item " " "command-sequence buffer-begin ; buffer-end-select"
		Separator
		Item "   ()..." "dialog-show findreplace"
		Item "   ( )..." "dialog-show findreplaceadv"
		Separator
		Item "  " "paragraph-move-up"
		Item "  " "paragraph-move-down"
		Separator
		Submenu " " "edit_textstyles"
		LanguageSelector
		Item " ..." "layout-paragraph"
		Separator
# Mathed b0rkage means these don't work properly
		OptSubmenu "" "edit_tabular"
		OptSubmenu "" "edit_maths"
		OptSubmenu ",  ," "edit_tabular_features"
		Separator
# This is where the context-specific stuff is supposed to go.
# The idea is that everything on here can disappear and should
# only appear when relevant (getStatus). Only stuff that needs
# a right-click to bring up the dialogue should appear here (it is not
# obvious what the context is for the others)
		OptItem "  |I" "depth-increment"
		OptItem "  |D" "depth-decrement"
		OptItem " " "inset-dissolve"
		OptItem "TeX  ...|C" "inset-settings ert"
# 'a' shortcut to match Insert entry, shouldn't clash with Table Settings
		OptItem "Float ...|a" "inset-settings float"
		OptItem "  ...|W" "inset-settings wrap"
		OptItem " ...|N" "inset-settings note"
		OptItem " ...|h" "inset-settings phantom"
		OptItem " ...|B" "inset-settings branch"
		OptItem " ...|x" "inset-settings box"
		OptItem "   ...|y" "inset-settings index"
		OptItem "   ...|x" "inset-settings index_print"
		OptItem " ...|n" "inset-settings info"
		OptItem " ...|g" "inset-settings listings"
# Hey, guess what's broken ? Surprise surprise, it's tabular stuff
# This is in the Table submenu instead for now.
#	OptItem " ...|a" "inset-settings tabular"
		OptItem " ...|a" "layout-tabular"
	End

	Menu "edit_paste"
		OptItem "    HTML" "paste html"
		OptItem "    LaTeX" "paste latex"
		OptItem "    PDF  " "paste linkback"
		OptItem "   PDF" "paste pdf"
		OptItem "   PNG" "paste png"
		OptItem "   JPEG" "paste jpeg"
		OptItem "   EMF" "paste emf"
		Separator
		Item " " "clipboard-paste"
		Item " ,  " "clipboard-paste paragraph"
		Separator
		Item "" "primary-selection-paste"
		Item ",  " "primary-selection-paste paragraph"
# clipboard-paste-simple is commented because it is irritating (bug 8749)
# until somebody can explain why it is needed in addition to clipboard-paste
#		Separator
#		Item " " "clipboard-paste-simple"
#		Item " ,  " "clipboard-paste-simple paragraph"
	End

	Menu "edit_pasterecent"
		PasteRecent
	End

	Menu "edit_textstyles"
		Item "  " "inset-dissolve charstyle"
		CharStyles
		Elements
		Separator
		Item "...|C" "dialog-show character"
		Separator
		Item "Abc|a" "word-capitalize"
		Item "ABC|U" "word-upcase"
		Item "abc|L" "word-lowcase"
	End

# not much we can do to help here
	Menu "edit_tabular"
		Item " |g" "tabular-feature toggle-longtabular"
		Item " |F" "tabular-feature toggle-booktabs"
		Separator
		Item ",|M" "tabular-feature multicolumn"
		Item ",|u" "tabular-feature multirow"
		Separator
		Item " |T" "tabular-feature toggle-line-top"
		Item " |B" "tabular-feature toggle-line-bottom"
		Item " |L" "tabular-feature toggle-line-left"
		Item " |R" "tabular-feature toggle-line-right"
		Separator
		Item "|p" "tabular-feature tabular-valign-top"
		Item "|i" "tabular-feature tabular-valign-middle"
		Item "|o" "tabular-feature tabular-valign-bottom"
	End

	Menu "edit_tabular_features"
		Item "|L" "tabular-feature align-left"
		Item "|C" "tabular-feature align-center"
		Item "|R" "tabular-feature align-right"
		Separator
		Item "|T" "tabular-feature valign-top"
		Item "|M" "tabular-feature valign-middle"
		Item "|B" "tabular-feature valign-bottom"
		Separator
		Item " ,|A" "tabular-feature append-row"
		Item " ,|D" "tabular-feature delete-row"
		Item " ,|o" "tabular-feature copy-row"
		Item " , " "tabular-feature move-row-up"
		Item " , " "tabular-feature move-row-down"
		# Item " ,|S" "tabular-feature swap-row" # currently broken
		Separator
		Item " ,|u" "tabular-feature append-column"
		Item " ,|e" "tabular-feature delete-column"
		Item " ,|p" "tabular-feature copy-column"
		Item " , |v" "tabular-feature move-column-right"
		Item " , " "tabular-feature move-column-left"
		# Item " ,|w" "tabular-feature swap-column" # currently broken
	End

	Menu "edit_maths"
		Item "  |N" "math-number-toggle"
		Item "  |u" "math-number-line-toggle"
		Submenu "  |L" "edit_maths_limits"
		Submenu " " "edit_maths_macro_definition"
		Separator
		Submenu "  |F" "edit_maths_mutate"
		Separator
		Submenu " |T" "edit_maths_fontstyles"
		Separator
# here, 'Algebra' has been substituted with 'mathematics'
		Submenu "   |S" "edit_maths_extern"
		Separator
		Item "  |C" "cell-split"
		Separator
		Item "  |A" "tabular-feature add-hline-above"
		Item "  |B" "tabular-feature add-hline-below"
		Item "  |D" "tabular-feature delete-hline-above"
		Item "  |e" "tabular-feature delete-hline-below"
		Separator
		Item "  " "tabular-feature add-vline-left"
		Item "  " "tabular-feature add-vline-right"
		Item "  " "tabular-feature delete-vline-left"
		Item "  " "tabular-feature delete-vline-right"
	End

	Menu "edit_maths_macro_definition"
		Item " " "math-macro-add-param"
		Item " 1 " "math-macro-remove-param"
		Separator
		Item " 1    " "math-macro-make-optional"
		Item " 1    " "math-macro-make-nonoptional"
		Item "  " "math-macro-add-optional-param"
		Item "  " "math-macro-remove-optional-param"
		Separator
		Item "   " "math-macro-append-greedy-param"
		Item "    " "math-macro-add-greedy-optional-param"
		Item " 1    " "math-macro-remove-greedy-param"
	End

	Menu "edit_maths_limits"
		 Item "|t"  "math-limits empty"
		 Item "|D"  "math-limits limits"
		 Item "|I"  "math-limits nolimits"
	End

	Menu "edit_maths_fontstyles"
		Item "  |N" "math-font-style mathnormal"
		Separator
		Item " Calligraphic   |C" "math-font-style mathcal"
		Item " Formal Script   |o" "math-font-style mathscr"
		Item " Fraktur   |F" "math-font-style mathfrak"
		Item " Roman   |R" "math-font-style mathrm"
		Item "      |S" "math-font-style mathsf"
		Separator
		Item "    |B" "math-font-style mathbf"
		Separator
		Item "  |T" "math-font-style textnormal"
		Separator
		Item " Roman    " "math-font-style textrm"
		Item "      " "math-font-style textsf"
		Item " Typewriter    " "math-font-style texttt"
		Separator
		Item "    " "math-font-style textbf"
		Item "    " "math-font-style textmd"
		Separator
		Item "    " "math-font-style textit"
		Item "  ABC " "math-font-style textsc"
		Item "  " "math-font-style textsl"
		Item "  " "math-font-style textup"
	End

	Menu "edit_maths_extern"
		Item "Octave|O" "math-extern octave"
		Item "Maxima|M" "math-extern maxima"
		Item "Mathematica|a" "math-extern mathematica"
		Separator
		Item "Maple, Simplify|S" "math-extern maple simplify"
		Item "Maple, Factor|F" "math-extern maple factor"
		Item "Maple, Evalm|E" "math-extern maple evalm"
		Item "Maple, Evalf|v" "math-extern maple evalf"
	End

	Menu "edit_maths_mutate"
		Item "Inline Formula|I" "math-mutate simple"
		Item "Displayed Formula|D" "math-mutate equation"
		Item "Eqnarray Environment|E" "math-mutate eqnarray"
		Item "AMS align Environment|a" "math-mutate align"
		Item "AMS alignat Environment|t" "math-mutate alignat"
		Item "AMS flalign Environment|f" "math-mutate flalign"
		Item "AMS gather Environment|g" "math-mutate gather"
		Item "AMS multline Environment|m" "math-mutate multline"
	End

#
# VIEW MENU
#

	Menu "view"
		Item "  |O" "inset-forall * inset-toggle open"
		Item "  |C" "inset-forall * inset-toggle close"
		Separator
		Item "  |n" "math-macro-unfold"
		Item "  |d" "math-macro-fold"
		Separator
		Item "  |u" "dialog-toggle toc"
		Item "   |P" "dialog-toggle view-source"
		Item "LyX  |g" "dialog-toggle progress"
		Submenu "" "toolbars"
		Separator
		Item "       |i" "view-split horizontal"
		Item "       |e" "view-split vertical"
		OptItem "  |w" "tab-group-close"
		Item " |l" "ui-toggle fullscreen"
		Separator
		Documents
	End

	Menu "toolbars"
		Toolbars
		Separator
		Item " " "toolbar-movable *"
		Separator
		Item " " "icon-size small"
		Item "  " "icon-size normal"
		Item " " "icon-size big"
		Item " " "icon-size huge"
		Item " " "icon-size giant"
	End
#
# INSERT MENU
#
	Menu "insert"
# Try and group things a little better, and percolate the most
# commonly used to good positions (exception being mathed, but
# most people using mathed learn key shortcuts quite quickly anyway)
		Submenu "" "insert_maths"
		Submenu " |p" "insert_special"
		Submenu "|o" "insert_formatting"
		Submenu "    |i" "insert_toc"
		Submenu "|a" "insert_float"
		Submenu "|N" "insert_note"
		Submenu "|B" "insert_branches"
		Submenu " " "insert_custom"
		Submenu "|e" "insert_file"
		Submenu "[[]]|x" "insert_box"
		OptSubmenu "  " "context-edit-regexp"
		Separator
		Item "...|C" "dialog-show-new-inset citation"
		Item " ...|R" "dialog-show-new-inset ref"
		Item "..." "label-insert"
		Captions
		Indices
		Item " ...|y" "nomencl-insert"
		Separator
		Item "...|T" "tabular-insert"
		Item "...|G" "dialog-show-new-inset graphics"
		Item " |U" "flex-insert URL"
		Item "...|k" "href-insert"
		Item "|F" "footnote-insert"
		Item "|M" "marginalnote-insert"
		Item " [[]]" "listing-insert"
		Item "" "date-insert"
		Separator
		EnvironmentSeparators
		Separator
		Arguments
		Separator
		Item " TeX " "ert-insert"
		Item " |w" "preview-insert"
	End

	Menu "insert_special"
		Item "Symbols...|b" "dialog-show symbols"
		Item "Ellipsis|i" "specialchar-insert dots"
		Item "End of Sentence|E" "specialchar-insert end-of-sentence"
		Item "Plain Quotation Mark|Q" "quote-insert outer auto plain"
		Item "Inner Quotation Mark|n" "quote-insert inner"
		Item "Protected Hyphen|y" "specialchar-insert nobreakdash"
		Item "Breakable Slash|a" "specialchar-insert slash"
		Item "Visible Space|V" "space-insert visible"
		Item "Menu Separator|M" "specialchar-insert menu-separator"
		Item "Phonetic Symbols|P" "ipa-insert"
		Submenu "Logos|L" "insert_logos"
	End

	Menu "insert_logos"
		Item "LyX Logo|L" "specialchar-insert lyx"
		Item "TeX Logo|T" "specialchar-insert tex"
		Item "LaTeX Logo|a" "specialchar-insert latex"
		Item "LaTeX2e Logo|e" "specialchar-insert latex2e"
	End

	Menu "insert_formatting"
		Item "Superscript|S" "script-insert superscript"
		Item "Subscript|u" "script-insert subscript"
		Separator
		Item "Protected Space|P" "space-insert protected"
		Item "Interword Space|w" "space-insert normal"
		Item "Thin Space|T" "space-insert thin"
		Item "Horizontal Space...|o" "command-alternatives dialog-show-new-inset space;dialog-show-new-inset mathspace"
		Item "Horizontal Line...|L" "dialog-show-new-inset line"
		Item "Vertical Space...|V" "dialog-show-new-inset vspace"
		Submenu "Phantom|m" "insert_phantom"
		Separator
		Item "Hyphenation Point|H" "specialchar-insert hyphenation"
		Item "Ligature Break|k" "specialchar-insert ligature-break"
		Item "Optional Line Break|B" "specialchar-insert allowbreak"
		Item "Ragged Line Break|R" "newline-insert newline"
		Item "Justified Line Break|J" "newline-insert linebreak"
		Separator
		Item "New Page|N" "newpage-insert newpage"
		Item "Page Break|a" "newpage-insert pagebreak"
		Item "Clear Page|C" "newpage-insert clearpage"
		Item "Clear Double Page|D" "newpage-insert cleardoublepage"
	End

	Menu "insert_maths"
# Always use "math-mode on" instead of "math-display" etc. because this disables the commands in maths mode
		Item "Inline Formula|I" "math-mode on"
		Item "Display Formula|D" "command-sequence math-mode on; math-mutate equation"
		Item "Numbered Formula|N" "command-sequence math-mode on; math-mutate equation; math-number-toggle;"
		Item "Eqnarray Environment|E" "command-sequence math-mode on; math-mutate eqnarray;"
		Item "AMS align Environment|a" "command-sequence math-mode on; math-mutate align;"
		Item "AMS alignat Environment|t" "command-sequence math-mode on; math-mutate alignat;"
		Item "AMS flalign Environment|f" "command-sequence math-mode on; math-mutate flalign;"
		Item "AMS gather Environment|g" "command-sequence math-mode on; math-mutate gather;"
		Item "AMS multline Environment|m" "command-sequence math-mode on; math-mutate multline;"
		Separator
# "math-matrix" and "math-insert" create an inline formula first if called from text mode
		Item "Array Environment|y" "math-matrix 2 2"
		Item "Cases Environment|C" "math-insert \cases"
		Item "Aligned Environment|l" "command-sequence math-insert \aligned; tabular-feature append-column"
		Item "AlignedAt Environment|v" "command-sequence math-insert \alignedat; tabular-feature append-column"
		Item "Gathered Environment|h" "math-insert \gathered"
		Item "Split Environment|S" "command-sequence math-insert \split; tabular-feature append-column"
		Separator
		Item "Delimiters...|r" "dialog-show mathdelimiter"
		Item "Matrix...|x" "dialog-show mathmatrix"
		Item "|o" "math-macro newmacroname newcommand"
	End

	Menu "insert_float"
		FloatInsert
# This has got to be better than "Wrap", anyway
		Item "  |F" "wrap-insert figure"
		Item "  |T" "wrap-insert table"
	End

	Menu "insert_toc"
		Item "  |C" "inset-insert toc"
		FloatListInsert
		IndicesLists
		Item "  |L" "inset-insert toc CommandInset toc LatexCommand lstlistoflistings \end_inset"
		Item "|N" "nomencl-print"
		Item " Bib(La)TeX  ...|B" "dialog-show-new-inset bibtex"
	End

	Menu "insert_file"
		Item "LyX Document...|X" "file-insert"
		Item " ...|T" "file-insert-plaintext"
		Item " ,  ...|J" "file-insert-plaintext-para"
		Separator
		Item "External Material...|M" "dialog-show-new-inset external"
		Item "Child Document...|d" "dialog-show-new-inset include"
	End

	Menu "insert_box"
		Item "Frameless|l" "box-insert Frameless"
		Item "Simple Frame|F" "box-insert Boxed"
		Item "Oval, Thin|a" "box-insert ovalbox"
		Item "Oval, Thick|v" "box-insert Ovalbox"
		Item "Drop Shadow|w" "box-insert Shadowbox"
		Item "Shaded Background|B" "box-insert Shaded"
		Item "Double Frame|u" "box-insert Doublebox"
	End

	Menu "insert_note"
		Item "LyX Note|N" "note-insert Note"
		Item "Comment|C" "note-insert Comment"
		Item "Greyed Out|G" "note-insert Greyedout"
	End

	Menu "insert_branches"
		Branches
		Separator
		Item "Insert New Branch...|I" "branch-add-insert"
	End

	Menu "insert_phantom"
		Item "Phantom|P" "phantom-insert Phantom"
		Item "Horizontal Phantom|H" "phantom-insert HPhantom"
		Item "Vertical Phantom|V" "phantom-insert VPhantom"
	End

	Menu "insert_custom"
		Custom
	End

#
# DOCUMENT MENU
#

	Menu "document"
		Submenu "Change Tracking|C" "document_change"
		OptItem "Build Program|B" "build-program"
		Item "LaTeX Log|L" "dialog-show latexlog"
		Item "Start Appendix Here|x" "appendix"
		Separator
		ViewFormats
		UpdateFormats
		OptItem " Master Document|M" "master-buffer-view"
		OptItem " Master Document|a" "master-buffer-update"
		Separator
		Item "Compressed|o" "buffer-toggle-compression"
		Item " |E" "buffer-toggle-read-only"
		Item "...|S" "dialog-show document"
	End

	Menu "document_change"
		Item "Track Changes|T" "changes-track"
		Item "Merge Changes...|M" "changes-merge"
		Item "Accept Change|A" "change-accept"
		Item "Reject Change|R" "change-reject"
		Item "Accept All Changes|c" "all-changes-accept"
		Item "Reject All Changes|e" "all-changes-reject"
		Item "Show Changes in Output|S" "changes-output"
	End

#
# NAVIGATE MENU
#
	Menu "navigate"
		Submenu "Bookmarks|B" "navigate_bookmarks"
		Item "Next Note|N" "note-next"
		Item "Next Change|C" "change-next"
		Item "Next Cross-Reference|R" "reference-next"
		OptItem "Go to Label|L" "label-goto"
		Item "Forward Search|F" "forward-search"
		Separator
		Toc
	End

	Menu "navigate_bookmarks"
		Item "Save Bookmark 1|S" "bookmark-save 1"
		Item "Save Bookmark 2" "bookmark-save 2"
		Item "Save Bookmark 3" "bookmark-save 3"
		Item "Save Bookmark 4" "bookmark-save 4"
		Item "Save Bookmark 5" "bookmark-save 5"
		Item "Clear Bookmarks|C" "bookmark-clear"
		Separator
		Item "Navigate Back|B" "bookmark-goto 0"
		Bookmarks
	End

#
# TOOLS MENU
#

	Menu "tools"
		Item "Spellchecker...|S" "dialog-show spellchecker"
		OptItem "Thesaurus...|T" "thesaurus-entry"
		Item "  ...|a" "statistics"
		Item "  TeX|h" "buffer-chktex"
		Item "TeX |I" "dialog-show texinfo"
		Item "...|C" "dialog-show compare"
		Separator
# A LOT of applications have Tools->Prefs. Remember this
# should be rarely used - Edit menu is not a good place to
# have it.
		Item "|R" "reconfigure"
		Item "...|P" "dialog-show prefs"
	End

#
# HELP MENU
#
	Menu "help"
		Item "|I" "help-open Intro"
		Item "|T" "help-open Tutorial"
		Item " |U" "help-open UserGuide"
		Item " |F" "help-open Additional"
		Item " |O" "help-open EmbeddedObjects"
		Item "|M" "help-open Math"
		Item "|C" "help-open Customization"
		Item "abc |S" "help-open Shortcuts"
		Item "LyX |y" "help-open LFUNs"
		Item "LaTeX Configuration|L" "help-open LaTeXConfig"
		Submenu " |p" "examples"
		Separator
		Item "  LyX|X" "dialog-show aboutlyx"
	End

	Menu "examples"
		Item "Beamer Presentations|B" "help-open beamer"
		Item "Braille|a" "help-open Braille"
		Item "Coloured boxes|r" "help-open colored-boxes"
		Item "Feynman-diagram|F" "help-open FeynmanDiagrams"
		Item "Knitr|K" "help-open knitr"
		Item "LilyPond|P" "help-open lilypond"
		Item "Linguistics|L" "help-open linguistics"
		Item "Multilingual Captions|C" "help-open MultilingualCaptions"
		Item "Paralist|t" "help-open paralist"
		Item "PDF comments|D" "help-open PDF-comment"
		Item "PDF forms|o" "help-open PDF-form"
		Item "Hazard and Precautionary Statements|H" "help-open H-P-statements"
		Item "Sweave|S" "help-open sweave"
		Item "XY-pic|X" "help-open xypic"
	End


End

