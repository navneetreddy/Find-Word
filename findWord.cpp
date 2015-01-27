/*******************************************************************************
Author:         Navneet Reddy
CS Login:       navneet
Course:         CS 368, Fall 2014
Assignment:     Programming Assignment 5
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <cstring>

using namespace std;

/*
 * Search for occurrences of given word within a given file.
 *
 * @param argc number of command line arguments passed.
 * @param argv[] array containing all the command line arguments.
 */
int main(int argc, char *argv[]) {
    //Check if the correct number of arguments are passed
    if (argc != 3)
    {
        cout << "Invalid number of arguments passed." << argc << endl;
        return 0;
    }
    
    //Convert word need to be found to a string
    string word = string(argv[1]);
    
    //Open the file from the file stream
    ifstream myFile(argv[2]);
    
    //Check if file can be opened
    if (myFile) 
    {
        string str;
        int count = 0;
        int lineNum = 0;
        char line[100];
        bool printed = false;
    
        //Read from the file one line at a time
	    while (!myFile.getline(line, 100).eof()) {
            //Increment current line number
    		lineNum++;
            
            //Convert each line from the file to a string
            string strline = string(line);
            
            //Length of each substring to compare to given word
            int i = 0;
            int j = word.length();
            
            printed = false;
            
            //Run through a line from the file 
            while (i+j < strline.length())
            {
                //Substring the same length as the given word
                str = strline.substr(i,j);
                
                //Check if the substring and the given word are equal
                //Print line if the substring and word are equal
                if (word.compare(str) == 0 && printed == false)
                {
                    cout << "Line " << lineNum << ": " << strline << endl;
                    count++;
                    printed = true;
                }
                else if (word.compare(str) == 0)
                {
                    count++;
                }
                    
                i++;
            }
    	}
        
        //Print total occurrances of the given word
        cout << "Total occurrances of '" << word << "' in this file: " << count << endl;

        //Close the file
        myFile.close();

        //Print error message and quit program if the file can't be opened
        } else {
            cerr << "Unable to open " << argv[2] << endl;
            myFile.close();
            return -1;
        }
}
