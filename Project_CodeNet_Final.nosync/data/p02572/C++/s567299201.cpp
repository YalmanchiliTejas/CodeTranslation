#include<bits/stdc++.h>
#define int long long
using namespace std;
int const MOD=1000000007;
int n,ans,a[233333],sum[233333];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--)sum[i]=(sum[i+1]+a[i])%MOD;
	for(int i=1;i<=n;i++)ans=(ans+a[i]*sum[i+1]%MOD)%MOD;
	cout<<ans<<endl;
}