
#include<bits/stdc++.h>
using namespace std;
 
const int N=10000010;
int n;
int fac[N],inv[N],ci[N];
const long long mod=998244353;
 
long long ksm(long long x,long long t){
	long long tot=1;
	while(t){
		if(t&1) (tot*=x)%=mod;
		(x*=x)%=mod;
		t/=2;
	}
	return tot;
}
 
long long C(int x,int y){
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
 
int main(){
	scanf("%d",&n);
	long long tot=0;
	fac[0]=ci[0]=1;for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod,ci[i]=ci[i-1]*2%mod;
	inv[n]=ksm(fac[n],mod-2);for(int i=n-1;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
	for(int i=n/2+1;i<=n;i++) tot+=C(n,i)*ci[n-i]%mod;
	printf("%lld\n",(ksm(3,n)-tot*2%mod+mod)%mod);
}
/*
————————————————
版权声明：本文为CSDN博主「Deep_Kevin」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/Deep_Kevin/java/article/details/102900391
*/