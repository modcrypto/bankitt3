
Debian
====================
This directory contains files used to package bankitzd/bankitz-qt
for Debian-based Linux systems. If you compile bankitzd/bankitz-qt yourself, there are some useful files here.

## bankitz: URI support ##


bankitz-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install bankitz-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your bankitzqt binary to `/usr/bin`
and the `../../share/pixmaps/bankitz128.png` to `/usr/share/pixmaps`

bankitz-qt.protocol (KDE)

