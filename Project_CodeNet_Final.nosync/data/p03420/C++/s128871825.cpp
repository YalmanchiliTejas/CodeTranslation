#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,K;
ll calc(ll x,int now){
	ll ans=0;
	for(ll i,j=now;j<x;){
		i=j+1;j=x/(x/i);
		ans+=(x/i)*(j-i+1);
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&K);
	ll ans=0;
	for(int i=K;i<=n;i++){
		ans+=calc(n-i,i);
		if(i) ans+=(n-i);
	}
	printf("%lld",ans);
	return 0;
}