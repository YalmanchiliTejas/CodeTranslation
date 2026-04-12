/**
*    created: 14.05.2020 11:20:16
**/
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int mx = 0;
    int cnt = 0;
    rep(i,n) {
        mx = max(mx, h[i]);
        if (mx <= h[i]) cnt++;
    }
    cout << cnt << endl; 
    return 0;
}