#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e3+5;
ll n,p,P,ans,fac[N],inv[N],a[N][N];
ll fsp(ll x,int y){
	ll ans=1;
	while(y){
		if(y&1)	ans=ans*x%P;
		x=x*x%P,y>>=1;
	}
	return ans;
}
ll ksm(ll x,int y){
	ll ans=1;
	while(y){
		if(y&1)	ans=ans*x%p;
		x=x*x%p,y>>=1;
	}
	return ans;
}
ll C(int n,int m){
	return fac[n]*inv[m]%P*inv[n-m]%P;
}
int main(){
	scanf("%lld%lld",&n,&P),p=P-1,a[0][0]=1;
	for(int i=1;i<=n+1;i++)
		for(int j=1;j<=i;j++)
			a[i][j]=(a[i-1][j-1]+j*a[i-1][j])%P;
	inv[0]=fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%P;
		inv[i]=fsp(fac[i],P-2);
	}
	for(int i=0;i<=n;i++){
		ll d=1,sum=0,tmp=fsp(2,n-i),res=fsp(2,ksm(2,n-i));
		for(int j=0;j<=i;j++){
			sum=(sum+a[i+1][j+1]*d)%P;
			d=d*tmp%P;
		}
		ans=(ans+(i&1?-1:1)*sum*res%P*C(n,i)%P+P)%P;
	}
	printf("%lld\n",ans);
	return 0;
}
