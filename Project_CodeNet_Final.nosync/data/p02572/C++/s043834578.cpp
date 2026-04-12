#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll mod = 1e9+7;
    int n;
    cin>>n;
    ll a[n];
    ll sum = 0;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	sum+=a[i];
    	sum%=mod;
	}
	
	ll ans=0;
 	for(int i=0;i<n;i++){
 		sum=(sum+mod-a[i])%mod;
 		ans=(ans+(a[i]*sum)%mod)%mod;
	 }
	 
	cout<<ans;
	return 0;
}