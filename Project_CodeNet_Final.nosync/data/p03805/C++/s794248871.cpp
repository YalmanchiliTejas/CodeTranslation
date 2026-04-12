#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n)repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)
typedef pair<int,int> P;
typedef pair<int, P> PP;
#define all(v) v.begin(),v.end()
#define fi first
#define se second
const int inf = 1e9;
int mod = 1e9+7;

vector<vector<int> > G(10);
int n, m;
int dfs(int u, int bit){
	if(bit == (1<<n)-1)return 1;
	int f = 0, res = 0;
	rep(i,G[u].size()){
		int to = G[u][i];
		if((bit&(1<<to)) == 0){
			res += dfs(to, bit|(1<<to));
			f = 1;
		}
	}
	if(f == 0)return 0;
	return res;
}

signed main(){
	scanf("%lld%lld", &n, &m);
	rep(i,m){
		int x, y;
		scanf("%lld%lld", &x, &y);
		G[x-1].push_back(y-1);
		G[y-1].push_back(x-1);
	}
	int ans = dfs(0, 1);
	printf("%lld\n", ans);
	return 0;
}