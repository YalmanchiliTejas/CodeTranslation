#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pll pair<ll,ll> 

const ll mod = 1e9+7;
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n;
	cin>>n;
	ll A[n], ans=0, s=0;
	for(ll i=0;i<n;i++){
		cin>>A[i];
		ans+=(A[i]*s)%mod;
		s+=A[i];
		ans%=mod;
		s%=mod;
	}
	cout<<ans<<endl;
}
