#include <bits/stdc++.h>

using namespace std;

int main() {
    char c; cin >> c;
    char a[5] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < 5; i++) {
        if (a[i] == c) {
            cout << "vowel" << "\n";
            exit(0);
        }
    }
    cout << "consonant" << "\n";
}