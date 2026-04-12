#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s = "aiueo";
    char c;
    cin >> c;

    string ans = "consonant";
    rep(i, 5) {
        if (s.at(i) == c) {
            ans = "vowel";
        }
    }
    cout << ans << endl;
}
