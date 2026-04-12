#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    string vowel = "aiueo";

    cin >> c;

    for (int i = 0; i < vowel.size(); i++) {
        if (c == vowel[i]) {
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;
    return 0;
}
