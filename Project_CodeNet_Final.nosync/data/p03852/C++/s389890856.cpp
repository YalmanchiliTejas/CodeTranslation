#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    char c; cin >> c;
    string vowel = "aeiou";
    if (find(vowel.begin(), vowel.end(), c) != vowel.end()) {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
    return 0;
}