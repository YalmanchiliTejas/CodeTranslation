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
		//f[j]表示必须选a[i]，总体积为j的方案数 
		for (register int j=m; j>a[i]; --j) f[j]=(f[j]+f[j-a[i]])%MOD;
		f[a[i]]=(f[a[i]]+i)%MOD;   //对于f[a[i]]，需要加上i，表示在[1,i]内枚举一个起点，而终点为i 
		ans=(ans+f[m]*(n-i+1)%MOD)%MOD; 
		f[m]=0;   //因为f[m]的定义为必须选a[i]，总体积为m的方案数，而下一步的必须选的是a[i+1]，所以清0
		//而为什么别的不用清0，因为别的不清0就相当于省略枚举了一个[1,i)中的j，只要直接累加f[]即可 
	}
	printf("%lld\n",ans);
return 0;
}
