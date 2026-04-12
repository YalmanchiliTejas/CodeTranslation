#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 30000

const LL mod=998244353;
LL n,s1,s2,ans,fac[N],ifac[N],f[10005][5005];
char a[N],b[N];

void upd(LL &x,LL y){x=(x+y)%mod;}

LL sqr(LL x){return x*x%mod;}

LL C(LL x,LL y){return fac[x]*ifac[y]%mod*ifac[x-y]%mod;}

LL inv(LL x){return x==1?1:(mod-mod/x)*inv(mod%x)%mod;}

int main(){
	scanf("%s%s",a+1,b+1); n=strlen(a+1);
	fac[0]=1; for (LL i=1;i<=n*2;++i) fac[i]=fac[i-1]*i%mod;
	ifac[n*2]=inv(fac[n*2]); for (LL i=n*2-1;i>=0;--i) ifac[i]=ifac[i+1]*(i+1)%mod;
	for (LL i=1;i<=n;++i)
		if (a[i]=='1'&&b[i]=='1') ++s1;
		else if (a[i]=='1'||b[i]=='1') ++s2;
	s2/=2; f[s1][s2]=1;
	for (int i=s1;i>=0;--i)
		for (int j=s2;j>=0;--j){
			if (i>0) upd(f[i-1][j],f[i][j]*i%mod*j%mod);
			if (j>0) upd(f[i][j-1],f[i][j]*sqr(j)%mod);
		}
	for (int i=0;i<=s1;++i)
		upd(ans,f[i][0]*sqr(fac[i])%mod*C(s1+s2,i)%mod);
	printf("%lld\n",ans);
	
	return 0;
}
			