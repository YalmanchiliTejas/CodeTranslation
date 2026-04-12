#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,a[1000010],ans;
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	if(n&1){
		ll x=n/2;
		for(ll i=1;i<=x;i++)
		ans+=a[n-i+1];
		ans*=2;
		for(ll i=1;i<=n-x;i++)ans-=a[i];
		for(ll i=1;i<=n-x-2;i++)ans-=a[i];
		ll ans2=0;
		for(ll i=1;i<=x+1;i++)ans2+=a[n-i+1];
		for(ll i=1;i<=x-1;i++)ans2+=a[n-i+1];
		for(ll i=1;i<=n-x-1;i++)ans2-=a[i]*2;
		cout<<max(ans,ans2)<<endl;
	 	return 0;
	}
	else{
		ll x=n/2;
		for(ll i=1;i<=x;i++)
		ans+=a[n-i+1];
		ans*=2;
		ans-=a[n-x+1];
		for(ll i=1;i<=x;i++)
		ans-=a[i]*2;
		ans+=a[x];
		cout<<ans<<endl; 
	}
	return 0;
}
/*
*/ 