#include<bits/stdc++.h>

#define ntest 0

using namespace std;
int n;
long long a[200005], f[201000], res;
const int mod = 1e9 + 7;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        f[i] = f[i-1] + a[i];
    }
    res = 0;
    for (int i = 2; i <= n; ++i) {
        res = (res + (a[i] * (f[i-1]%mod) % mod)) % mod;
    }
    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if(ntest){
        int t;
        cin >> t;
        while(t--) solve();
    } else {
        solve();
    }

}


