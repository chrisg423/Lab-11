/*
*
*   Name: Chris Gallagher
*   Lab 11
*  
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cctype>
using namespace std;

ifstream inStream; // in and out variables
ofstream outStream;

int main(int argc, char *argv[]) {
    string fileName = "Text.txt";
    inStream.open(fileName.c_str());
    if (inStream.fail()) {
        cout << "Error: The input file: " << fileName << " does not exist." << endl;
        exit(1); // always check for failure
    }

    string outFileName; // get output file name because it is to be determined
    cout << "Enter an output file name: ";
    cin >> outFileName;
    outStream.open(outFileName.c_str());
    if (outStream.fail()) {
        cout << "Error: The output file: " << outFileName << " does not exist.";
        exit(1); // always check for failure
    }

    char ch; // input character
    inStream.get(ch);
    while (!inStream.eof()) { // while not end of file
        bool capLetter = isupper(ch); // checks for capital letter
        bool digit = isdigit(ch); // checks to see if it is a digit
        if (capLetter == false && digit == false) { // if it isn't a capital letter or a digit, make it uppercase
            ch = toupper(ch);
            outStream << ch;
        }
        else if (digit == true) { // if it is a digit, censor it
            outStream << "*";
        }
        else { // if none of those conditions qualify, just output the file
            outStream << ch;
        }
        inStream.get(ch);
    }

    inStream.close(); // close files
    outStream.close();

    cout << "Done." << endl;
}