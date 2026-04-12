#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
const ll MAX = 1001001;
const ll MOD = 1000000007;
const ll INF = 1001001001;
int main()
{
    ll n;
    cin >> n;

    vector<ll> a(n), b(n + 1);
    rep(i, n)
    {
        cin >> a[i];
        b[i + 1] = b[i] + a[i];
    }
    ll ans = 0;
    rep(i, n)
    {
        ans += (b[n] - b[i + 1]) % MOD * a[i];
        ans %= MOD;
    }
    cout << ans << endl;
}