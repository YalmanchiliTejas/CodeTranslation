#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
ll M=1e9+7;
int main()
{
	ll n,ans=0,x=0;
	cin>>n;
	vector<ll> vec(n+1,0);
	for(ll i=1;i<=n;i++){
		cin>>vec[i];
		vec[i]=vec[i]%M;
		ans+=(x*vec[i]);
		ans=(ans%M);
		x+=vec[i];
		x=(x%M);
	}
	cout<<ans<<endl;
	
}
