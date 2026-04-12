#include <bits/stdc++.h>
using namespace std;

int main() {
    char c[1];
    cin >> c[0];

    if (c[0] == 'a' || c[0] == 'e' || c[0] == 'i' || c[0] == 'o' || c[0] == 'u') {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
    return 0;
}