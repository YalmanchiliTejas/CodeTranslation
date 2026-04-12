#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    string s;
    cin >> s;
    if (s == "a" || s == "e" || s == "i" || s == "o" || s == "u") {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
}
