#include<cstdio>
#define maxn 10000005
#define tt 998244353
#define LL long long
using namespace std;
int n,ans,fac[maxn],inv[maxn];
inline int C(int n,int m){return (LL)fac[n]*inv[m]%tt*inv[n-m]%tt;}
inline int qsm(int a,int b){
	int s=1,w=a%tt;
	while (b){
		if (b&1) s=(LL)s*w%tt;
		w=(LL)w*w%tt;
		b>>=1;
	}
	return s;
}
int main(){
	scanf("%d",&n);
	fac[0]=1;for (int i=1;i<=n;i++) fac[i]=(LL)fac[i-1]*i%tt;
	inv[1]=1;for (int i=2;i<=n;i++) inv[i]=(LL)inv[tt%i]*(tt-tt/i)%tt;
	inv[0]=1;for (int i=1;i<=n;i++) inv[i]=(LL)inv[i-1]*inv[i]%tt;
	ans=qsm(3,n);
	for (int i=n/2+1;i<=n;i++) ans=(ans-(LL)2*C(n,i)*qsm(2,n-i)%tt)%tt;
	printf("%d\n",(ans+tt)%tt);
	return 0;
}