#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    int c[26]{51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51};
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < 26; j++) {
            if (c[j] > 0) {
                int t = 0;
                for (int k = 0; k < s.size(); k++) {
                    t += (s[k] == (char)('a' + j) ? 1 : 0);
                }
                c[j] = min(c[j], t);
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < c[i]; j++) {
            cout << (char)('a' + i);
        }
    }
    cout << endl;
}
