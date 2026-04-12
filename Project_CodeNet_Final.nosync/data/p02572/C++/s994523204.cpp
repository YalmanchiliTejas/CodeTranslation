#include <bits/stdc++.h>
#define ll long long int
#define mk make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mod 1000000007
using namespace std;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int main(){
    fast();
    ll t=1;
//    cin>>t;
    while(t--){
    	ll n,ans=0;
    	cin>>n;
    	ll a[n],pre[n];
    	for(ll i=0;i<n;i++)cin>>a[i],pre[i]=a[i]%mod,a[i]=a[i]%mod;
    	for(ll i=1;i<n;i++){
    		pre[i]=(pre[i]%mod+pre[i-1]%mod)%mod;
		}
		for(ll i=0;i<n-2;i++){
			ans=(ans%mod+((a[i])%mod*((pre[n-1]-pre[i]+mod)%mod))%mod)%mod;
//			cout<<ans<<" ";
		}
		ans=(ans%mod+(a[n-1]%mod*a[n-2]%mod)%mod)%mod;
		cout<<ans%mod;
	}
}