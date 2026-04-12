#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int>pii;
const int maxn = 2e5 + 100;
const int mod = 1e9 + 7;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int n, m, k;
ll fac[maxn], inv[maxn];
ll pwr(ll a, ll pw)
{
    ll ret = 1;
    while(pw > 0)
    {
        if(pw & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        pw >>= 1;
    }
    return ret;
}
ll modinv(ll a)
{
    return pwr(a, mod - 2);
}
ll choose(int N, int K)
{
    return fac[N] * inv[K] % mod * inv[N - K] % mod;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    fac[0] = inv[0] = 1;
    for(ll i = 1; i < maxn; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = modinv(fac[i]);
    }
    cin >> n >> m >> k;
    ll times = choose(n * m - 2, k - 2);
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ll a = 1ll * i * (i - 1) / 2 % mod;
        ans = (ans + a * times % mod * m % mod * m % mod) % mod;
    }
    for(int j = 1 ; j <= m; j++)
    {
        ll a = 1ll * j * (j - 1) / 2 % mod;
        ans = (ans + a * times % mod * n % mod * n % mod) % mod;
    }
    cout << ans << "\n";
    return 0;
}
