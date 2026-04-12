//  main.cpp
//  CppTest

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    
    /////////////////////
    // Write code below /
    /////////////////////
    char c;
    cin >> c;
    const string vowel = "aeiou";
    if (vowel.find(c) == string::npos) {
        cout << "consonant" << endl;
    } else {
        cout << "vowel" << endl;
    }
    
    return 0;
}
