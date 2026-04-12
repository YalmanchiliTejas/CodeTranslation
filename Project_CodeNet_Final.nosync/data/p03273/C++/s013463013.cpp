#include <bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i = m; i < (int)(n); ++i)
#define rep(i,n) REP(i, 0, n)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    string s[h];
    rep(i, h) cin >> s[i];

    rep(j, w) {
        bool all_dot = true;
        rep(i, h) if (s[i][j] == '#') all_dot = false;
        if (all_dot) {
            rep(i, h) s[i].erase(s[i].begin() + j);
            j--, w--;
        }
    }

    string t = "";
    rep(i, w) t.push_back('.');
    rep(i, h) if (s[i] != t) cout << s[i] << endl;

    return 0;
}

