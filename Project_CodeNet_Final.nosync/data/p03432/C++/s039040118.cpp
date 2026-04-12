#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch < '0' || ch > '9')	{if(ch == '-')	f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return x * f;
}
const int N = 8005 , M = 205 , mod = 998244353 , G = 3 , Ginv = (mod + 1) / 3;
int n , m;
ll f[N][M] , A[N << 2] , B[N << 2] , fac[N] , inv[N];
int r[N << 2];
inline ll ksm(ll a,int b)
{
	ll res = 1;
	while(b)
	{
		if(b & 1) res = res * a % mod;
		a = a * a % mod; b >>= 1;
	}
	return res;
}
namespace Poly
{
	inline void NTT(int lim,ll *a,int type)
	{
		for(int i = 0;i < lim;i ++) r[i] = (r[i >> 1] >> 1) | (i & 1 ? lim >> 1 : 0);
		for(int i = 0;i < lim;i ++) if(i < r[i]) swap(a[i],a[r[i]]);
		for(int k = 1;k < lim;k <<= 1)
		{
			ll Wn = ksm(type == 1 ? G : Ginv,(mod - 1) / (k << 1));
			for(int i = 0;i < lim;i += k << 1)
			{
				ll w = 1;
				for(int j = 0;j < k;j ++ , w = w * Wn % mod)
				{
					ll x = a[i + j] , y = w * a[i + j + k] % mod;
					a[i + j] = (x + y) % mod; a[i + j + k] = (x - y + mod) % mod;
				}
			}
		}
		if(type == 1) return;
		ll inv = ksm(lim,mod - 2);
		for(int i = 0;i < lim;i ++) a[i] = a[i] * inv % mod;
	}
	inline void MUL(int n,ll *a,int m,ll *b)
	{
		int lim = 1;
		while(lim <= (n + m)) lim <<= 1;
		NTT(lim,a,1); NTT(lim,b,1);
		for(int i = 0;i < lim;i ++) a[i] = a[i] * b[i] % mod;
		NTT(lim,a,-1);
	}
}
inline void init(int n)
{
	fac[0] = inv[0] = 1;
	for(int i = 1;i <= n;i ++) fac[i] = fac[i - 1] * i % mod;
	inv[n] = ksm(fac[n],mod - 2);
	for(int i = n - 1;i >= 1;i --) inv[i] = inv[i + 1] * (i + 1) % mod;
}
inline void solve(int j)
{
	memset(A,0,sizeof A);
	memset(B,0,sizeof B);
	using namespace Poly;
	for(int i = 1;i <= n;i ++) A[i] = inv[i + 2];
	for(int i = 0;i <= n;i ++) B[i] = f[i][j - 1] * inv[i] % mod;
	MUL(n + 1,A,n + 1,B);
	for(int i = 0;i <= n;i ++) f[i][j] = f[i][j - 1] * (1 + i + i * (i - 1) / 2) % mod;
	for(int i = 1;i <= n;i ++) f[i][j] = (f[i][j] + A[i] * fac[i + 2]) % mod;
}
inline ll C(int n,int m) { return fac[n] * inv[m] % mod * inv[n - m] % mod;}
int main()
{
	n = read(); m = read(); ll ans = 0;
	init(n + 2); f[0][0] = 1;
	for(int i = 1;i <= m;i ++) solve(i);
	for(int i = 0;i <= n;i ++) ans = (ans + C(n,i) * f[i][m]) % mod;
	printf("%lld\n",ans);
	return 0;
}