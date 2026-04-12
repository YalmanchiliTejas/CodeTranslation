#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int n,s,a[3005];
ll dp[3005],ans=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>s; 
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		dp[0]++;
		for(int j=s;j>=a[i];j--){
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
//			cout<<j<<" "<<dp[j]<<endl;
		}
		ans=(ans+dp[s])%mod;
	} 
	cout<<ans;
	return 0;
} 