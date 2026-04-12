#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.0000000001
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
#define ff first
#define ss second

void solve() {
    const int Mod = (int) 1e9 + 7;
    int n;
    cin >> n;
    vector<int> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        sum %= Mod;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        sum -= a[i];
        sum = (sum % Mod + Mod) % Mod;
        ans += a[i] * 1ll * sum;
        ans %= Mod;
    }
    cout << ans << endl;
}

int main() {
//    freopen("input.txt" , "r" , stdin) ;
//    freopen("output.txt" , "w" , stdout) ;
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}