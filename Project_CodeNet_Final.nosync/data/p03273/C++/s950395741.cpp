#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int H, W;
char a[110][110];
bool f1[110], f2[110];
vector<vector<char>> ans;

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> H >> W;
    rep(i, H) rep(j, W) cin >> a[i][j];
    rep(i, H) f1[i] = true;
    rep(i, H) rep(j, W) f1[i] &= (a[i][j]=='.');
    rep(i, W) f2[i] = true;
    rep(i, W) rep(j, H) f2[i] &= (a[j][i]=='.');
    
    rep(i, H) {
        if (f1[i]) continue;
        vector<char> v;
        rep(j, W) {
            if (f2[j]) continue;
            v.pb(a[i][j]);
        }
        ans.pb(v);
    }
    rep(i, ans.size()) {
        rep(j, ans[0].size()) cout << ans[i][j];
        cout << endl;
    }
}