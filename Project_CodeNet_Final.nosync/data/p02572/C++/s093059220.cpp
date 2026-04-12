#include <bits/stdc++.h>
#define ll long long int
#define mod int(1e9+7)
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	ll ans=0ll,pre=1ll*a[0];
	for(int i=1;i<n;i++){
		ans=(ans+(pre*1ll*a[i])%mod)%mod;
		pre=(pre+1ll*a[i])%mod;
	}
	cout<<ans<<endl;
	return 0;
}