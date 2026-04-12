#include<iostream>
#include<algorithm>
#define ll long long 
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 2e5 + 10000;
ll f[maxn]; ll inv[maxn];

void init()
{
	f[0] = 1;
	for (int i = 1; i < maxn; i++) f[i] = (f[i - 1] * i) % mod;
}

ll POW(ll a, ll b, ll mod)
{
	ll s = 1;
	while (b != 0)
	{
		if (b & 1) s = s * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return s % mod;
}

ll Lucas(ll n, ll k, ll p)        //C (n, k) % p
{
	ll ret = 1;
	while (n && k)
	{
		ll nn = n % p, kk = k % p;
		if (nn < kk) return 0;  //inv (f[kk]) = f[kk] ^ (p - 2) % p
		ret = ret * f[nn] * POW(f[kk] * f[nn - kk] % p, p - 2, p) % p;
		n /= p, k /= p;
	}
	return ret;
}
int main()
{
	init();
	ll N; ll M; ll K;
	cin >> N >> M >> K;
	ll ans = 0;
	for (ll d = 1; d < N; d++)
		ans = (ans + (N - d) % mod * M % mod * M % mod * d % mod) % mod;
	for (ll d = 1; d < M; d++)
		ans = (ans + (M - d) % mod * N % mod * N % mod * d % mod) % mod;

	ans = ans * Lucas(N * M - 2, K - 2, mod) % mod;
	cout << ans % mod << endl;

	return 0;
}