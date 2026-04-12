#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int n,a[200005],bc[200005],ans=0;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--) bc[i]=a[i]+bc[i+1],bc[i]%=mod;
	for(int i=1;i<=n;i++){
		ans+=(a[i]*bc[i+1]);
		ans%=mod;
	}
	cout<<ans;
	return 0;
}