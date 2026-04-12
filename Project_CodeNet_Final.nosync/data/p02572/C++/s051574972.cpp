#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	const ll MOD=1000000007;
	ll n=0,ans=0,sum=0;
	cin>>n;
	vector<ll> a(n);
	for(ll i=0;i<n;i++){
	       	cin>>a[i];
		sum+=a[i];
		sum%=MOD;
	}
	for(ll i=0;i<n-1;i++){
		sum-=a[i];
		if(sum<0) sum+=MOD;
		ans+=a[i]*sum;
		ans%=MOD;
	}
	cout<<ans<<'\n';
	return 0;
}