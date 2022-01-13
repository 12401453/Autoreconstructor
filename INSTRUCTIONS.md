If you know how to compile C++ programs then just download everything in this repository (the "Executables" and "TOROT texts" folder are not needed) into a single directory, then compile "main.cpp". (g++ on my Manjaro Linux distribution will hang indefinitely; in this case use clang++. It compiles fine on Windows using the Visual Studio compiler and on my Debian-based distributions).

Alternatively just download the correct compiled executable file from the "Executables" folder (this will be flagged by any antivirus software or Windows Defender as dangerous because executable binaries are just CPU machine-code and they could do anything).

1. Put the TOROT text file in the same folder/directory as the Autoreconstructor program
2. Run the Autoreconstructor program
    -   Windows: just double click the .exe file
    -   Linux: navigate to the directory in the terminal and type `chmod +x Autoreconstructor_Linux` and enter, then `./Autoreconstructor_Linux`
3. Type in the filename of the text to be autoreconstructed.
4. The auto-reconstructed text is a .csv file with pipe ('|') as the separator; in Windows opening it directly into Excel will not show the foreign characters correctly and will assume comma ',' as the separator, so one must either view it in Notepad or import it into an existing Excel spreadsheet using the "import from csv" functionality in Excel.
