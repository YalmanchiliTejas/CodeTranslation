#include<cstdio>
#define mod 998244353
long long n,s,f1[3005][3005],f2[3005][3005],a[3005],p[3005],ans;
int main(){
	scanf("%lld%lld",&n,&s);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]),p[i]=p[i-1]+a[i];
	for(int i=1;i<=n;++i){
		(f1[i][a[i]]+=i)%=mod;
		for(int j=0;j<=s;++j){
			f2[i][j]+=f2[i-1][j];
			if(j>a[i])
				(f1[i][j]+=f2[i-1][j-a[i]])%=mod;
			(f2[i][j]+=f1[i][j])%=mod;
		}
		ans=(ans+f1[i][s]*(n-i+1)%mod)%mod;
	}
	return printf("%lld",ans),0;
}