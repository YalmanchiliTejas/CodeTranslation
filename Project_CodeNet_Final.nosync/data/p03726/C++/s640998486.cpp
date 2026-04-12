//Nipah!~☆
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

int n;
string ans;
bool mark[maxn];
int kid[maxn];
vector<int> adj[maxn];

void in();
void solve();
void dfs(int, int);
void out();

int main(){
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	in();
	solve();
	out();
}

void in(){
	cin >> n;
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void solve(){
	ans = "Second";
	dfs(0, -1);
}

void dfs(int u, int par){
	mark[u] = 1;
	kid[u] = -1;
	for(auto v: adj[u])
		if(!mark[v])
			dfs(v, u);
	if(kid[u] == -1){
		if(par == -1 || kid[par] != -1)
			ans = "First";
		else
			kid[par] = u;
	}
}

void out(){
	cout << ans;
}
