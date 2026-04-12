#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int N=3005;
int a[N],f[N];
int n,s;
int main() {
	ll ans=0;
	int i,j;
	cin>>n>>s;
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=1;i<=n;i++) {
		f[0]++;
		for (j=s;j>=1;j--)
			if (j>=a[i]) f[j]=(f[j]+f[j-a[i]])%mod;
		ans=(ans+f[s])%mod;
	}
	cout<<ans<<endl;
	return 0;
}