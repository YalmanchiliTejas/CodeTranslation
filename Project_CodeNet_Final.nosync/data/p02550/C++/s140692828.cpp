#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "[(" << __LINE__ << ") " << #x << "]: " << (x) << endl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, x, MOD;
    cin >> n >> x >> MOD;

    vector<pair<ll, int>> m(MOD+1);

    ll ans = 0;
    ll i=1;
    while (!m[x].second && i <= n) {
        m[x] = {ans, i++};
        ans += x;
        x = x*x % MOD;
    }

    n -= i;
    if (n < 0) { 
        cout << ans << "\n";
        return 0;
    }
    ll duh = n / (i-m[x].second);
    ans += duh * (ans-m[x].first);
    n %= i-m[x].second;
    n++;

    while (n-- > 0) {
        ans += x;
        x = x*x % MOD;
    }
    cout << ans << "\n";
}
