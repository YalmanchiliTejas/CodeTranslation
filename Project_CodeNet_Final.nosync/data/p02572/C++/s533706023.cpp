#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &x)
#define slld(x) scanf("%lld", &x)
#define all(x) x.begin(), x.end()
#define For(i, s, e) for (ll i = s; i < e; i++)
#define Forr(i, s, e) for (ll i = s; i > e; i--)
#define pb push_back
#define ll long long
#define int ll
#define mp make_pair
ll mod = 1000000007;
ll mod2 = 500000004;
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    cout << fixed << setprecision(8);
    ll n;
    cin >> n;
    ll a[n];
    ll sum = 0;
    For(i, 0, n)
    {
        cin >> a[i];
        sum += a[i] % mod;
    }
    ll ans = 0;
    For(i, 0, n)
    {

        ll x1 = (sum - (a[i] % mod)) % mod;
        ll x2 = ((a[i] % mod) * (x1 % mod)) % mod;
        ans += x2 % mod;
    }
    ans = ((ans % mod) * (mod2)) % mod;
    cout << ans << endl;
    return 0;
}