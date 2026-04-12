#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    cin >> c;
    vector <char> vowels{'a', 'e', 'i', 'o', 'u'};
    for (char v: vowels) {
        if (c==v) {
            cout << "vowel\n";
            return 0;
        }
    }
    cout << "consonant\n";
}