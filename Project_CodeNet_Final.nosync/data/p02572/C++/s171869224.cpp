#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
 
#define int long long
#define endl "\n"
#define deb(x) cout << #x << " -> " << x << endl;
#define print(x)                         \
    for (auto x_ : x) cout << x_ << " "; \
    cout << endl;
#define pb push_back
#define all(x) x.begin(), x.end()
#define mod 1000000007  // 1e9 + 7
#define prec(x, y) fixed << setprecision(y) << x
 
void solve() {
    int n;
    cin >> n;
    int sum = 0;
    int prefix[n] = {};
    int a[n];
    for (auto &x : a) cin >> x, sum += x;
    prefix[0] = a[0];
    for (int i = 1; i < n; ++i) prefix[i] = ((prefix[i - 1] + a[i]) % mod);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int t = (a[i] * (prefix[n - 1] - prefix[i])) % mod;
        res = (t + res) % mod;
    }
    res = (res + mod)%mod;
    cout << (res % mod) << endl;
}
 
int32_t main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
 
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
}