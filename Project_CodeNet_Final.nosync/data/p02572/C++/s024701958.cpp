#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastt ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll mod=1e9+7;

int main()
{
	fastt

	ll n;
	cin>>n;
	ll ar[n+10],br[n+10];
	memset(ar,0,sizeof(ar));
	memset(br,0,sizeof(br));
	for(ll i=1;i<=n;i++){
		cin>>ar[i];
		br[i]=ar[i];
	}
	for(ll i=1;i<=n;i++){
		ar[i]+=ar[i-1];
	}
	ll ans=0;
	for(ll i=1;i<n;i++){
		ll sum=ar[n]-ar[i];
		ll cnt=((sum%mod)*(br[i]%mod))%mod;
		ans=(ans+cnt)%mod;
	}
	cout<<ans<<endl;
		
	return 0;
}

