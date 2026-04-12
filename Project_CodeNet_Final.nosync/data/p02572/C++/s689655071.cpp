#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1e9+7;
int main() {
	int n;
	cin>>n;
	vector<ll> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<ll> suff(n);
	suff[n-1]=a[n-1]%mod;
	for(int i=n-2;i>=0;i--) suff[i]=(a[i]+suff[i+1])%mod;
	ll ans=0;
	for(int i=0;i<=n-2;i++){
	    ans=(ans+(a[i]*suff[i+1])%mod)%mod;
	}
	cout<<ans;
	return 0;
}