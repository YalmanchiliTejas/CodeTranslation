#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,p,c[3010][3010],s[3010][3010],ans;
ll ksm(ll x,ll y){
	ll xlh=1;
	while(y){
		if(y&1)xlh=xlh*x%p;
		x=x*x%p;
		y/=2;
	}
	return xlh;
}
ll kxm(ll x,ll y){
	ll xlh=1;
	while(y){
		if(y&1)xlh=xlh*x%(p-1);
		x=x*x%(p-1);
		y/=2;
	}
	return xlh;
}
ll solve(ll x){
	ll j,now=1,sum=0,hh=ksm(2,kxm(2,n-x)),ha=ksm(2,n-x);
	for(j=0;j<=x;j++){
		sum=(sum+s[x][j]*now%p*hh%p)%p;
		now=now*ha%p;
	}
	return sum;
}
int main(){
	ll i,j,hh;
	scanf("%d%d",&n,&p);
	for(i=0;i<=n;i++)c[i][0]=1;
	for(i=1;i<=n;i++)
	 for(j=1;j<=i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%p;
	s[0][0]=s[1][1]=1;
	for(i=1;i<=n;i++){
		s[i][0]=1;
		for(j=1;j<=i;j++)s[i][j]=(s[i-1][j-1]+s[i-1][j]*(j+1))%p;
	}
	hh=1;
	for(i=0;i<=n;i++){
	  ans=(ans+hh*c[n][i]%p*solve(i)%p)%p;
	  hh=(-hh+p)%p;
	  //printf("%lld\n",hh);
  }
     printf("%lld",ans);
}