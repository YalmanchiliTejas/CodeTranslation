#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = unsigned long long;
using P = pair<int, int>;
const ll mod = 1'000'000'007;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    int w = 0; // 横方向の長さを保持する変数
    rep(i, n)
    {
        ans = (ans + a[i] * w) % mod;
        w = (w + a[i]) % mod;
    }
    cout << ans << endl;
}
