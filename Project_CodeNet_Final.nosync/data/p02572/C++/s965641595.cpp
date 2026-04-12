#include <iostream>
#include <vector>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;

const ll mod = 1e9+7;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> smod(n+1);
    for(int i = n-1; i >= 0; i--) {
        smod[i] = (smod[i+1] + a[i]) % mod;
    }
    ll ans = 0;
    rep(i,n-1) {
        ans += a[i] * smod[i+1];
        ans %= mod;
    }
    cout << ans%mod << endl;

    return 0;
}
