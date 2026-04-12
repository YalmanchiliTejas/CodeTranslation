#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <set>
#include <map>
#define re register
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define MAXN 3007
#define ll long long
using namespace std;
typedef unsigned long long ull;
#define ms(arr) memset(arr, 0, sizeof(arr))
const int inf = 0x3f3f3f3f;
ll c[MAXN][MAXN];
ll g[MAXN][MAXN];
ll n,mo;
inline ll niubide_power(ll k,ll x,ll mod)
{
	ll ans=1;
	while(x) {
		if(x&1ll) ans=ans*k%mod;
		k=(k*k%mod);
		x>>=1;
	}
	return ans;
}
int main()
{
	cin>>n>>mo;
	for(re int i=1;i<=n;i++){
		c[i][0]=1;c[i][i]=1;
		for(int j=1;j<i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mo;
	}
	for(int i=0;i<=n;i++){
		g[i][0]=1;
		for(int j=1;j<=i;j++)
			g[i][j]=(g[i-1][j-1]+g[i-1][j]*(j+1)%mo)%mo;
	}
	ll ans=0;
	for(int i=0;i<=n;i++){
		ll k=c[n][i];
		if(i&1) k=(mo-k)%mo;
		ll kind=niubide_power(2,n-i,mo);
		ll x=niubide_power(2,n-i,mo-1);
		x=niubide_power(2,x,mo);
		ll cnt=0,y=1;
		for(int j=0;j<=i;j++){
			cnt=(cnt+(g[i][j]*y)%mo)%mo;
			y=kind*y%mo;
		}
		ans=(ans+(k*cnt)%mo*x%mo)%mo;
	}
	cout<<ans;
}