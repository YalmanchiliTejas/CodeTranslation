#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
const int MAXN = 2e5+3;
ll A[MAXN],N;
ll dp[MAXN][3];
ll dfs(int now, int left){
	if(left < 0 || now >= N) return -1e18;
	if(now+left >= N) return -1e18;
	if(now+left == N-1) return dp[now][left] = A[now]; 
	if(dp[now][left] != -1) return dp[now][left];
	return dp[now][left] = max(dfs(now+2,left),max(dfs(now+3,left-1),dfs(now+4,left-2)))+A[now];
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	for(int i=0;i<N;i++) cin >> A[i];
	memset(dp,-1,sizeof(dp));
	if(N&1){
		ll ans = max(dfs(0,2),max(dfs(1,1),dfs(2,0)));
		cout << ans << '\n';
	}
	else{
		ll ans = max(dfs(0,1),dfs(1,0));
		cout << ans << '\n';
	}
	return 0;
}