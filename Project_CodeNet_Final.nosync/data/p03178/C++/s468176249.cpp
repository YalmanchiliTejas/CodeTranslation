#include <bits/stdc++.h>
#define int LL
using namespace std;
typedef long long LL;
const int MAX_N=10005;
const int MAX_D=105;
const int Mod=1e9+7;
string k;
int D;
int dp[MAX_N][MAX_D];
int dfs(int pos,int sum,bool limit) {
	if (pos==k.size()) return (sum%D)?0:1;
	if (!limit && dp[pos][sum]!=-1) return dp[pos][sum];
	int u = limit?k[pos]-'0':9;
	int ret = 0;
	for (int i=0; i<=u; ++i) {
		ret += dfs(pos+1,(sum+i)%D,limit && i==k[pos]-'0');
		ret%=Mod;
	}
	if (!limit) dp[pos][sum] = ret;
	//  cout<<"dfs("<<pos<<","<<sum<<","<<limit<<")="<<ret<<endl;
	return ret;
}
signed main() {
	memset(dp,-1,sizeof(dp));
	cin>>k>>D;
	cout<<(dfs(0,0,true)-1+Mod)%Mod<<endl;
	return 0;
}
