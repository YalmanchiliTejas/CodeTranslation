#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod=1e9+7;
int main() {
	int n;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	ll sum[n];
	sum[n-1]=a[n-1];
	for(int i=n-2;i>0;i--){
	    sum[i]=(a[i]+sum[i+1])%mod;
	}
	ll ans=0;
	for(int i=0;i<n-1;i++){
	    ans=(ans+(a[i]*sum[i+1])%mod)%mod;
	}
	cout<<ans;
	return 0;
}
