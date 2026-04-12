#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

const ll MOD = 1e9+7;

int main() {
    ll n;
    cin >> n;
    ll s = 0, ans = 0;
    rep(i,n) {
        ll a;
        cin >> a;
        ans += a*s;
        s += a;
        s %= MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
