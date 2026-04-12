#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e3+5,MOD=998244353;
int n,m,ans;
int a[N],f[N]; 
signed main(){
	scanf("%lld%lld",&n,&m);
	for (register int i=1; i<=n; ++i) scanf("%lld",&a[i]); 
	for (register int i=1; i<=n; ++i)
	{
		for (register int j=m; j>a[i]; --j) f[j]=(f[j]+f[j-a[i]])%MOD;
		f[a[i]]=(f[a[i]]+i)%MOD;
		ans=(ans+f[m]*(n-i+1)%MOD)%MOD;
		f[m]=0;
	}
	printf("%lld\n",ans);
return 0;
}
