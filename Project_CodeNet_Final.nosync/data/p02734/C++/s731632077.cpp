#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
const int MOD=998244353;
int n,S,dp[3003][3003],a[3003],NUM[3003];
int main(){
	cin>>n>>S;
	for (int i=1;i<=n;i++) cin>>a[i];
	dp[0][0]=1,NUM[0]=1;
	for (int i=1;i<=n;i++){
		for (int j=a[i];j<=S;j++)
			dp[i][j]=NUM[j-a[i]];
		for (int j=a[i];j<=S;j++) NUM[j]+=dp[i][j],NUM[j]%=MOD;
		ans=(ans+1ll*dp[i][S]*(n-i+1))%MOD;
		NUM[0]++;
	}
	cout<<ans;
}