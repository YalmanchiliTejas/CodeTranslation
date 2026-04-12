#include<bits/stdc++.h>
using namespace std;
const long long md=998244353;
const int maxn=1e7+10;
long long fac[maxn],inv[maxn];
long long powd(long long x,long long y){
	long long res=1;
	while(y){
		if(y&1) res=res*x%md;
		x=x*x%md;
		y>>=1;
	}
	return res;
}
long long C(int x,int y){
	return fac[x]*inv[y]%md*inv[x-y]%md;
}
int main(){
	int n;
	scanf("%d",&n);
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%md;
	inv[n]=powd(fac[n],md-2);
	for(int i=n;i>=1;i--)
		inv[i-1]=inv[i]*i%md;
	long long ans=powd(3,n);
	for(int i=n/2+1;i<=n;i++)
		ans=(ans-C(n,i)*powd(2,n-i)*2%md+md)%md;
	printf("%lld\n",ans);
	return 0;
}
