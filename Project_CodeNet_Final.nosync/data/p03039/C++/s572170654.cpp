#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mo = 1e9 + 7;
const int MAXM = 2e5 + 10;
inline ll fpm(ll a, ll b = mo - 2)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1) ans = ans * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return ans;
}
const ll inv2 = fpm(2);
ll fact[MAXM], invfac[MAXM];
#define sum(x) ((x)*(x+1)%mo*inv2%mo)
template <class T>
inline void _read(T &x)
{
    x = 0;
    char t = getchar();
    while (!isdigit(t) && t != '-') t = getchar();
    if (t == '-')
    {
        _read(x);
        x *= -1;
        return ;
    }
    while (isdigit(t))
    {
        x = x * 10 + t - '0';
        t = getchar();
    }
}
inline void pre()
{
    fact[0] = invfac[0] = 1;
    fact[1] = invfac[1] = 1;
    for(int i = 2; i < MAXM; ++i) fact[i] = 1ll * i * fact[i - 1] % mo, invfac[i] = fpm(fact[i]);
}
inline ll C(ll n, ll r)
{
    if(n < r || r < 0 || n < 0) return 0;
    return fact[n] * invfac[r] % mo * invfac[n - r] % mo;
}
ll n, m, k;
int main()
{
	pre();
	_read(n), _read(m), _read(k);
	ll ans = 0;
	for (ll i = 0; i < n; ++i)
	{
		for (ll j = 0; j < m; ++j)
		{
			ans = (ans + ((sum(i) + sum(n - i - 1)) % mo) * m % mo) % mo;
			ans = (ans + ((sum(j) + sum(m - j - 1)) % mo) * n % mo) % mo;
		}
	}
	ans = ans * C(n * m - 2, k - 2) % mo * inv2 % mo;
	printf("%lld\n", ans);
	return 0;
}