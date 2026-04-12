#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define ep emplace_back
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
constexpr int mod=1000000007;
constexpr int mod1=998244353;
vector<int> dx={0,1,0,-1},dy={-1,0,1,0};
bool inside(int y,int x,int h,int w){
	if(y<h && y>=0 && x<w && x>=0) return true;
	return false;
}


int n,m;
int ans = 0;
vector<vector<int>> g(8,vector<int>());
vector<bool> visited(8);

void dfs(int cur){
	bool ok = true;
	rep(i,n){
		if(!visited.at(i)) ok = false;
	}
	if(ok){
		ans++;
		return;
	}
	rep(i,g[cur].size()){
		int next = g[cur][i];
		if(!visited.at(next)){
			visited.at(next) = true;
			dfs(next);
			visited.at(next) = false;
		}
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i,m){
		int a,b;cin >> a >> b;
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	visited.at(0) = true;
	dfs(0);
	cout << ans << endl;
}
