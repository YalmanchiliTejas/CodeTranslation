#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;
 
#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(i, a) for (auto &i: (a))
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)

void solve();

signed main () {
    clock_t beg = clock();
    cout << fixed << setprecision(15);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif 
    int t = 1; 
    // cin >> t;    
    int tt = t;
    while (t--) {
        // cout << "Case #" << tt - t << ": "; 
        solve();
    }
    cerr << "\nExecution time: " << (clock() - beg) / 1000 << '\n';
    return 0;
}
int su = 0;
void solve() {  
    int n;
    cin >> n;
    const int M = 1e9 + 7;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans += (x * su) % M;
        ans %= M;
        su += x;
        su %= M;
    }
    cout << ans;
}       