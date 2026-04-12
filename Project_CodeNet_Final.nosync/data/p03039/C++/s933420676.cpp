#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7,maxn=200005;
int sum1,sum2,n,m,k,ans,f[maxn];
int calsum() {
	int sum=0;
	for(register int i=1; i<n; i++) {
		sum=(sum+(n-i)*i)%mod;
	}
	sum=sum*m%mod*m%mod;
	return sum;
}
int ksm(int x,int y) {
	int sum=1;
	while(y) {
		if(y&1) {
			sum=sum*x%mod;
		}
		x=x*x%mod;
		y>>=1;
	}
	return sum;
}
void fact() {
	f[0]=1;
	for(register int i=1; i<maxn; i++) {
		f[i]=f[i-1]*i%mod;
	}
}
int C(int x,int y) {
	return f[y]*ksm(f[x],mod-2)%mod*ksm(f[y-x],mod-2)%mod;
}
signed main() {
	scanf("%lld%lld%lld",&n,&m,&k);
	sum1=calsum();
	swap(n,m);
	sum2=calsum();
	ans=(sum1+sum2)%mod;
	fact();
	ans=ans*C(k-2,n*m-2)%mod;
	printf("%lld",ans);
	return 0;
}