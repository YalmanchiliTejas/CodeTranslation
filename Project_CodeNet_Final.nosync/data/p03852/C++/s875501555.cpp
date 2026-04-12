#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    char c; cin >> c;
    string vowel = "aeiou";
    if (vowel.find(c) != string::npos) {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
    return 0;
}