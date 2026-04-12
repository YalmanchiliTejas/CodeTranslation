#include <bits/stdc++.h>
using namespace std;
#define AC 0
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	const int mod=1e9+7;
	int n;
	cin>>n;
	vector<int> a(n),sum(n+1);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=n-1;i>=0;i--) sum[i]=(sum[i+1]+a[i])%mod;
	int ans=0;
	for(int i=0;i<n-1;i++) ans=(ans+1ll*a[i]*sum[i+1]%mod)%mod;
	cout<<ans<<'\n';
	return AC;
}
