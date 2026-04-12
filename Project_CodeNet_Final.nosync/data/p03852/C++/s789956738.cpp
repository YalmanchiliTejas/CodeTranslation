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
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
    
    return 0;
}
