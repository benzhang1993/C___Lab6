//
// Created by benzh on 2018-11-02.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "dictionary.hpp"

/**
 * Constructs a dictionary with provided filename, file name haas format " word definition"
 */
dictionary::dictionary(string filename) {
    ifstream file;
    file.open(filename);
    string line;
    while(getline(file, line)) {
        istringstream iss(line);
        string word;
        string definition;
        iss >> word;
        getline(iss, definition);
        getline(iss, definition);
        map.insert(pair<string, string>(word, definition));
    }
}

/**
 * Runs the main program with menu
 */
void dictionary::run() {
    cout << "i. 1 - Print dictionary\nii. 2 - Find word definition\niii. 3 - Enter new word and definition\niv. 4 - Exit" << endl;
    int choice;
    bool ended = false;
    while(!ended) {
        cin >> choice;
        if (choice == 1) {
            for(auto it = map.begin(); it != map.end(); ++it) {
                cout << it->first << " " << it->second << "\n";
            }
        }
        else if (choice == 2) {
            cout << "Please enter a word" << endl;
            string word;
            cin >> word;
            if(findWord(word)) {
                cout << "Word found:\n" << "Word: " << word << "\nDefinition: " << map.at(word) << endl;
            }
            else {
                cout << "the word doesn't exist" << endl;
            }
        }
        else if (choice == 3) {
            string word;
            cout << "Please enter new word" << endl;
            cin >> word;
            while (findWord(word)) {
                cout << "Word already exists, please enter a different word." << endl;
                cin >> word;
            }
            string definition;
            cout << "Please enter a definition" << endl;
            // first removes the \n not removed by previous cin >> word;
            getline(cin, definition);
            getline(cin, definition);
            map.insert(pair<string, string>(word, definition));
            cout << "The word and definition has been added." << endl;
        }
        else if (choice == 4) {
            break;
        }

        cout << "\ni. 1 - Print dictionary\nii. 2 - Find word definition\niii. 3 - Enter new word and definition\niv. 4 - Exit" << endl;
    }
}

/**
 * Checks if a word exists in the dictionary
 */
bool dictionary::findWord(string word) {
    auto it = map.find(word);
    if(it == map.end()) {
        return false;
    }
    else {
        return true;
    }
}