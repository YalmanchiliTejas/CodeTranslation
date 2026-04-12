#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;
const int MOD = 1000000007;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> s(n);
    s[0] = a[0];
    ll ans=0;
    for (int i=1; i< n; ++i) {
        s[i] = s[i-1] + a[i];
        s[i] %= MOD;
    }
    rep (i, n) {
        if (s[n-1] - s[i] < 0) s[n-1] += MOD;
        ans += a[i] * (s[n-1] - s[i]);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}