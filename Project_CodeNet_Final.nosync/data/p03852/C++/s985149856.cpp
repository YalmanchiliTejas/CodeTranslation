#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    bool vc=false;
    cin >> c;

    if (c == 'a') {
        vc = true;
    }
    else if (c == 'e') {
        vc = true;
    }
    else if (c == 'i') {
        vc = true;
    }
    else if (c == 'o') {
        vc = true;
    }
    else if (c == 'u') {
        vc = true;
    }
    if (vc) {
        cout << "vowel" << endl;
    }
    else {
        cout << "consonant" << endl;
    }
}