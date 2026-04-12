#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}


int n,m;
vector<vector<int>> e;

bool all(vector<int> v){
	REP(i,v.size()){
		if(v[i]==-1){
			return false;
		} 
	}
	return true;
}

int dfs(int parent, vector<int> visited){
	visited[parent] = 1;
	if(all(visited)){
		return 1;
	}
	
	int ret=0;
	for(auto child: e[parent]){
		if(visited[child]==1) continue;
		
		ret += dfs(child, visited);
	}
	return ret;
}

int main(){
	
	cin >> n >> m;
	e.resize(n);
	REP(i,m){
		int a,b;
		cin >> a >> b;
		a--; b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	
	vector<int> visited(n, -1);
	int ans = dfs(0, visited);
	
	cout << ans << endl;
	
	return 0;
}