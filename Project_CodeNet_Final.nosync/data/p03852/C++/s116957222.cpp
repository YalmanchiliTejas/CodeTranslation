#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s = "aiueo";
    char c;
    cin >> c;
    bool b = false;
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == c) {
            b = true;
            break;
        }
    }
    if (b) {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
}