#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i, a, b) for(int i = a; i < (int)b; ++i)
#define rrep(i, n) for(int i = ((int)n - 1); i >= 0; --i)

typedef long long ll;
typedef long double ld;

const int Inf = 1e9;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> cnt(26, Inf);
    rep (i, n) {
        string s;
        cin >> s;
        vector<int> tmp(26);
        rep (j, s.size()) tmp[s[j] - 'a']++;
        rep (j, 26) cnt[j] = min(cnt[j], tmp[j]);
    }
    rep (i, 26) {
        rep (j, cnt[i]) cout << char('a' + i);
    }
    cout << endl;
    
    return 0;
}

