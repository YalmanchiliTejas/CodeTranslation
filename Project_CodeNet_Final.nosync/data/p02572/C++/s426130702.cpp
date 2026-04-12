#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ull unsigned ll
#define pb push_back
#define mp make_pair
 
using namespace std;

ll mod=1e9+7;

int main(){
	int n;cin>>n;
	ll a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll suf[n+1];
	suf[n]=a[n];
	for(int i=n-1;i>=1;i--)suf[i]=suf[i+1]+a[i];
	ll ans=0;
    for(int i=1;i<n;i++){
    	ans+=(a[i]*(suf[i+1]%mod))%mod;
    	ans%=mod;
	}
	cout<<ans;
	return 0;
}
	

	
