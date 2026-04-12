#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
#define ll long long
const int mod=1e9+7;
const int mxN=2e5;
ll a[mxN+1];
int main(){
	int n;
	cin>>n;
	ll s=0;
	for(int i=0;i<n;i++){
        cin>>a[i];
        s=(s+a[i])%mod;
	}
	ll ans=0;
	for(int i=0;i<n;i++){
        s=(s-a[i]+mod)%mod;
        ans=(ans+s*a[i])%mod;
	}
	cout<<ans;
}
