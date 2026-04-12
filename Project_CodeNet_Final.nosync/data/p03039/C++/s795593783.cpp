#include <cstdio>
#define int long long
const int mod = 1e9+7,maxn = 2e5+5;
int n,m,k,jc[maxn],Ans;
inline int inv(int a){
	int x = mod-2,base = a,ans = 1;
	while(x){
		if(x&1)ans = ans*base%mod;
		base = base*base%mod;
		x >>= 1;
	}
	return ans;
}
int shik,row[maxn],col[maxn];
signed main(){
	scanf("%lld %lld %lld",&n,&m,&k);
	jc[0] = 1;
	for(int i=1;i<=n*m;++i)jc[i] = jc[i-1]*i%mod;
	shik = jc[n*m-2]*inv(jc[k-2])%mod*inv(jc[n*m-k])%mod;
	row[1] = m*(m-1)%mod*inv(2)%mod;
	col[1] = n*(n-1)%mod*inv(2)%mod;
	for(int i=2;i<=m;++i)row[i] = (row[i-1] - (m+2-2*i))%mod;
	for(int i=2;i<=n;++i)col[i] = (col[i-1] - (n+2-2*i))%mod;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			Ans = (Ans+shik*((row[j]*n%mod+col[i]*m)%mod)%mod)%mod;
	printf("%lld",Ans*inv(2)%mod);
	return 0;
}