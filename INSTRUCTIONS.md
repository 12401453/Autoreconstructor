If you know how to compile C++ programs then just download everything in this repository (the "Executables" and "TOROT texts" folder are not needed) into a single directory, then compile "main.cpp". (g++ on my Manjaro Linux distribution will hang indefinitely; in this case use clang++. It compiles fine on Windows using the Visual Studio compiler and on my Debian-based distributions).

Alternatively just download the correct compiled executable file from the "Executables" folder (this will be flagged by any antivirus software or Windows Defender as dangerous because executable binaries are just CPU machine-code and they could do anything).

1. Put the TOROT text file in the same folder/directory as the Autoreconstructor program
2. Run the Autoreconstructor program
    -   Windows: just double click the .exe file
    -   Linux: navigate to the directory in the terminal and type "./Autoreconstructor_Linux"
3. Type in the filename of the text to be autoreconstructed.
4. The auto-reconstructed text is a .csv file; in Windows opening it directly in Excel will not show the foreign characters correctly, so one must either view it in Notepad or open it with Notepad and "Save as" and then in the "encoding" dropdown menu change it from "UTF" to "UTF with BOM". Then it will display properly in Excel.
