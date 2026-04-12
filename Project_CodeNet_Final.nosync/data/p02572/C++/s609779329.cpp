#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[200005],y[200005];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=n-1;i>=1;i--)y[i]=x[i+1]+y[i+1];
	int mod=1e9+7;
	int ans=0;
	for(int i=1;i<n;i++){
	//	cout<<x[i]<<" "<<y[i]<<endl;
		ans+=x[i]*(y[i]%mod)%mod;
	//	cout<<ans<<endl;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
} 