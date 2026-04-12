#include <bits/stdc++.h>
using namespace std;

int main() {
    char C;
    cin >> C;

    if (C == 'a' || C == 'e' || C == 'i' || C == 'o' || C == 'u') {
        cout << "vowel" << endl;
    }
    else {
        cout << "consonant" << endl;
    }

    return 0;
}