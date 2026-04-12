#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 50010;
const ll mod = 998244353;

ll fac[maxn], inv[maxn];
int m,e;
ll res[maxn], t[maxn];

ll qpow(ll a, ll b)
{
	ll t = a, ret = 1LL;
	while (b)
	{
		if (b&1) ret = ret * t % mod;
		t = t * t % mod;
		b >>= 1;
	}
	return ret;
}

bool hasInit = false;

int findroot(int p)
{
	for (int i=2;i<=p;i++)
	{
		int x = p-1;
		bool flg = false;
		for (int j=2;j*j<=x;j++)
		{
			if (x % j != 0) continue;
			if (qpow(i,(p-1)/j) == 1)
			{
				flg = true;
				break;
			}
			while (x % j == 0) x /= j;
		}
		if (x != 1)
		{
			if (qpow(i,(p-1)/x) == 1) flg = true;
		}
		if (!flg) return i;
	}
}

struct NumericTheoreticTransform
{
	ll omega[maxn], omegainverse[maxn];
	int rev[maxn];

	void init(const int n)
	{
		if (hasInit) return;
		hasInit = true;
		int d = 0;
		while ((1<<d) < n) d++;
		for (int i=0;i<n;i++)
		{
			int t = 0;
			for (int j=0;j<d;j++) if (i & (1<<j)) t |= (1<<(d-1-j));
			rev[i] = t;
		}

		ll g = findroot(mod);
		ll x = qpow(g,(mod-1)/n);
		for (int i=0;i<n;i++)
		{
			omega[i] = (i !=0 ? omega[i-1]*x%mod : 1LL);
			omegainverse[i] = qpow(omega[i],mod-2);
		}
	}

	void transform(ll *a, const int n, const ll *omega)
	{
		for (int i=0;i<n;i++)
		{
			if (rev[i] > i) swap(a[i],a[rev[i]]);
		}
		for (int l=2;l<=n;l<<=1)
		{
			int m = (l >> 1);
			for (ll *p = a; p<a+n;p+=l)
			{
				for (int i=0;i<m;i++)
				{
					ll t = omega[n/l*i] * p[i+m] % mod;
					p[i+m] = (p[i] - t + mod) % mod;
					p[i] = (p[i] + t) % mod;
				}
			}
		}
	}

	void dft(ll *a, const int n)
	{
		transform(a,n,omega);
	}

	void idft(ll *a, const int n)
	{
		transform(a,n,omegainverse);
		ll x = qpow(n,mod-2);
		for (int i=0;i<n;i++) a[i] = a[i] * x % mod;
	}
}ntt;

void multiply(ll *a1, const ll *a3, const int n1)
{
	ll a2[maxn];
	bool same = (a1 == a3);
	int n = 1;
	while (n < n1 + n1) n <<= 1;
	ntt.init(n);
	if (!same) for (int i=0;i<n;i++) a2[i] = a3[i];

	ntt.dft(a1,n); if (!same) ntt.dft(a2,n);
	for (int i=0;i<n;i++) a1[i] = a1[i] * (same ? a1[i] : a2[i]) % mod;
	ntt.idft(a1,n);
	for (int i=m+1;i<n;i++) a1[i] = 0;
}

void facqpow(int b)
{
	res[0] = 1;
	for (int i=0;i<=m;i++) t[i] = inv[i+1];
	while (b)
	{
		if (b&1) multiply(res,t,m+1);
		multiply(t,t,m+1);
		b >>= 1;
	}
}

int main()
{
	//freopen("E.in","r",stdin);
	string a,b;
	cin >> a >> b;
	int n = a.length();
	for (int i=0;i<a.length();i++)
	{
		if (a[i] != '1') continue;
		if (b[i] == '1') m++;
		else e++;
	}
	fac[0] = 1;
	for (int i=1;i<=n;i++)
	{
		fac[i] = fac[i-1] * i % mod;
		inv[i] = qpow(fac[i],mod-2);
	}
	facqpow(e);
	ll ans = 0;
	for (int i=0;i<=m;i++) (ans += res[i]) %= mod; //cout << res[i]<<" "; cout<<endl;
	ans = ans * fac[m] % mod * fac[e] % mod * fac[m+e] % mod;
	cout << ans << endl;
	return 0;
}

