#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 3005;
int n;
ll mod;
inline ll qpow(ll a, ll b, int c = mod)
{
	ll res = 1;
	for(; b; a = a*a%c, b >>= 1)
	    if(b&1)
	        res = res*a%c;
	return res;
}
ll f[MAXN][MAXN],c[MAXN][MAXN];

int main()
{
	cin >> n >> mod;
	ll ans = 0;
	f[0][0] = 1;
	for(int i = 1; i<=n+1; i++)
	    for(int j = 1; j<=i; j++)
	        f[i][j] = (f[i-1][j-1]+1ll*j*f[i-1][j]%mod)%mod;
	for(int i = 0; i<=n; i++)
	    c[i][0] = c[i][i] = 1;
	for(int i = 2; i<=n; i++)
	    for(int j = 1; j<i; j++)
	        c[i][j] = (c[i-1][j-1]+c[i-1][j])%mod;
    for(int i = 0; i<=n; i++)
	{
		ll s = qpow(2,n-i,mod-1);
	    ll t = c[n][i]*qpow(mod-1,i)%mod*qpow(2,s)%mod;
	    for(int j = 0; j<=i; j++)
	        ans = (ans+t*f[i+1][j+1]%mod*qpow(qpow(2,n-i),j)%mod)%mod;
    }
	cout << ans << endl;
	return 0;
}