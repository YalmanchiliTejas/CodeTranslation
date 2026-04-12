#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    char vowel[5] = {'a', 'i', 'u', 'e', 'o'};
    char c; cin >> c;
    for (int i = 0; i < 5; i++) {
        if (c == vowel[i]) {
            cout << "vowel";
            return 0;
        }
    }
    cout << "consonant" << endl;
    return 0;
}