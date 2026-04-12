#include <bits/stdc++.h>
#define newl "\n"
using namespace std;
using lli = long long int;
using vvint = vector <vector <int>>;
const int mod = 1e9 + 7;

const int N = 2e5 + 1;
vvint adj;
int n,m;
int ans;
vector <bool> vis;

bool check(int s){
	for(int u : adj[s]){
		if(!vis[u]) return false;
	}
	return true;
}

void all_paths(int s){
	if(check(s)){
		bool flag = 0;
		for(int i = 0;i < n;++i){
			if(!vis[i]){
				flag = 1;
				break;
			}
		}
		if(!flag) ++ans;
		return;
	}
	else{
		for(int u : adj[s]){
			if(!vis[u]){
				vis[u] = 1;
				all_paths(u);
				vis[u] = 0;
			}
		}
	}
	return;
}

void solve(){
	cin >> n >> m;
	adj = vvint(n,vector <int> (n));
	vis = vector <bool> (n,0);
	for(int i = 0;i < m;++i){
		int u,v;
		cin >> u >> v;
		--u,--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vis[0] = 1;
	all_paths(0);
	cout << ans << newl;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(10);
	#ifdef EXECUTE_LOCALLY
		   freopen("in.txt","r",stdin);
	#endif
	int t = 1;
	//cin >> t;
	while(t--) solve();
	#ifdef EXECUTE_LOCALLY
    	cout << setprecision(3) << "program time: " << (double)clock() / CLOCKS_PER_SEC << newl;
	#endif
	return 0;
}
