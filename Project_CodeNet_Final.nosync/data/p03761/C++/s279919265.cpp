#include <bits/stdc++.h>
using namespace std;

int n, f[30][55];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            f[s[j] - 'a'][i]++;
        }
    }

    for (int i = 0; i < 26; i++) {
        int mn = 1e9;
        for (int j = 0; j < n; j++) {
            mn = min(mn, f[i][j]);
        }

        for (int j = 0; j < mn; j++) {
            cout << (char) ('a' + i);
        }
    }
    cout << '\n';

    return 0;
}