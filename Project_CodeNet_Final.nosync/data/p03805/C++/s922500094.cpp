#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define LINF 100000000000000007LL
#define ll long long
using namespace std;
int dp[10][1000];
vector<int> nex[10];
int dfs(int pos,int vis){
	if( dp[pos][vis] != -1 )return dp[pos][vis];
	int res = 0;
	for(int i=0;i<nex[pos].size();i++){
		int nx = nex[pos][i];
		if( (vis>>(nx-1))%2 == 1){
			res += dfs( nx, vis-(1<<(nx-1)) );
		}
	}
	dp[pos][vis]=res;
	return res;
}
signed main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		nex[x].pb(y);
		nex[y].pb(x);
	}
	for(int i=0;i<9;i++){
		for(int j=0;j<999;j++){
			dp[i][j] = -1;
		}
	}
	dp[1][0]=1;
	int ans = 0;
	int mx = (1<<n)-1;
	for(int i=2;i<=n;i++){
		ans += dfs(i,mx-(1<<(i-1)));
	}
	cout<<ans<<endl;
	return 0;
}