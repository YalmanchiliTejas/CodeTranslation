#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main(){
	ll n;
	cin>>n;
	ll a[n];
	ll dp[n];
	for(int i=0;i<n;++i){
		if(i!=0){
			cin>>a[i];
			dp[i]=a[i]+dp[i-1];
		}else{
			cin>>a[i];
			dp[0]=a[0];
		}
	}
	ll mod = 1e9+7;
	ll ans=0;
	for(int i=0;i<n;++i){
		ans=(ans+(((dp[n-1]-dp[i])%mod)*(a[i]%mod))%mod)%mod;
		//cout<<a[n-1]-a[i]<<"\n";
	}
	cout<<ans;
}
