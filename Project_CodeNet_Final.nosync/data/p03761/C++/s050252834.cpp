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
    rep(i, 0, 26) {
        int mn = 100;
        rep(j, 0, n) {
            int cnt = 0;
            rep(k, 0, (int)s[j].size()) {
                if (s[j][k] == (char)(i + 'a')) {
                    cnt++;
                }
            }
            mn = min(mn, cnt);
        }
        rep(k, 0, mn) ans += (char)(i + 'a');
    }

    cout << ans << endl;
    return 0;
}
