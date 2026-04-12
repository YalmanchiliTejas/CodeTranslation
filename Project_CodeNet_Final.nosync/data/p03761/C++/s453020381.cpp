#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ALL(v) v.begin(), v.end()
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main() {
    int n;
    cin >> n;
    string s[n];
    rep(i, 0, n) cin >> s[i];

    string ans;
    for (char c = 'a'; c <= 'z'; c++) {
        int mn = 100;
        rep(i, 0, n) {
            int cnt = 0;
            rep(j, 0, (int)s[i].size()) {
                if (s[i][j] == c) cnt++;
            }
            mn = min(mn, cnt);
        }
        rep(i, 0, mn) ans += c;
    }

    cout << ans << endl;
    return 0;
}
