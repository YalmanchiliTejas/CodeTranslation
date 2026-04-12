#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<string> s(n);
    rep(i,n) cin >> s[i];

    vector<int> INF(26, 1e9);

    string ans;
    rep(i, n) {
        vector<int> cnt(26, 0);
        rep(j, s[i].size()) {
            ++cnt[s[i][j] - 'a'];
        }
        rep(j, 26) {
            INF[j] = min(INF[j], cnt[j]);
        }
    }

    rep(i, 26) {
        rep(j, INF[i]) {
            ans += (i + 'a');
        }
    }
    cout << ans << endl;
    return 0;
}