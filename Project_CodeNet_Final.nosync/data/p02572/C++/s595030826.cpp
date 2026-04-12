#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e6+5;
int main() {
	int n;cin>>n;
	std::vector<ll> pre(n+1);
	for(int i=1;i<=n;i++) cin>>pre[i];
	ll ans=0,sum=0;
	const int mod=1e9+7;
	for(int i=1;i<=n;i++) {
		ans=(ans+pre[i]*sum%mod)%mod;
		sum=(sum+pre[i])%mod;
	}    
	cout<<ans<<endl;
    return 0;
}