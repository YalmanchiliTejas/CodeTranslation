#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int INF=1e9+5;
const int N=3000+5;
const int mod=998244353;

int n,s;

ll a[N];
ll dp[N][N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>s;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i){
		dp[i][a[i]]=i;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=s;++j){
			if(j>=a[i]) dp[i][j]+=dp[i-1][j]+dp[i-1][j-a[i]];
			else dp[i][j]+=dp[i-1][j];
			dp[i][j]%=mod;
		}
	}	
	ll ans=0;
	for(int i=1;i<=n;++i) ans=(ans+dp[i][s])%mod;
	cout<<ans;
	return 0;
}
