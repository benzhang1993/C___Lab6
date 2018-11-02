//
// Created by benzh on 2018-11-02.
//

#ifndef C_LAB6_DICTIONARY_HPP
#define C_LAB6_DICTIONARY_HPP
#include <map>
#include <string>

using namespace std;

/**
 * A dictionary containing words and their definitions as pairs in a map.
 */
class dictionary {

    map<string, string> map;

public:
    dictionary(string filename);
    void run();
    bool findWord(string word);
    void enterNew(string word, string definition);
};


#endif //C_LAB6_DICTIONARY_HPP
