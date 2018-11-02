#include <iostream>
#include "dictionary.hpp"

int main() {
    dictionary d(string("../dictionary.txt"));
    d.run();
    return 0;
}