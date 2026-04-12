#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define mod 998244353

using namespace std;
typedef long long ll;
const int MAXN = 10000005;
int n;
ll fac[MAXN],inv[MAXN],fin[MAXN],pw[MAXN];
inline ll c(int a, int b)
    { return a<b?0:fac[a]*fin[b]%mod*fin[a-b]%mod; }
inline ll qpow(ll a, int b)
{
	ll res = 1;
	for(; b; a = a*a%mod, b >>= 1)
	    if(b&1)
	    	res = res*a%mod;
	return res;
}

int main()
{
	cin >> n;
	inv[1] = 1;
	for(int i = 2; i<=n; i++)
		inv[i] = inv[mod%i]*(mod-mod/i)%mod;
	fac[0] = fin[0] = 1;
	for(int i = 1; i<=n; i++)
		fac[i] = fac[i-1]*i%mod, fin[i] = fin[i-1]*inv[i]%mod;
	pw[0] = 1;
	for(int i = 1; i<=n; i++)
		pw[i] = pw[i-1]*2%mod;
	ll ans = qpow(3,n);
	for(int i = n/2+1; i<=n; i++)
		ans = (ans-2*c(n,i)*pw[n-i]%mod+mod)%mod;
	cout << ans << endl;
	return 0;
}
