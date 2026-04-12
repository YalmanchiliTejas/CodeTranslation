#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n-1;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define ll long long

typedef pair<ll, ll> LP;

const int nmax = 8;
bool graph[nmax][nmax];


ll dfs(ll v, ll n, bool* visited){
	bool all_visited = true;
	REP(i, n){
		if (!visited[i]){ all_visited = false; break; }
	}
	if (all_visited){ return 1; }
	int ret = 0;
	REP(i, n){
		if (graph[v][i]==false){ continue; }
		if (visited[i]){ continue; }
		visited[i] = true;
		ret += dfs(i, n, visited);
		visited[i] = false;
	}
	return ret;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	REP(i, m){
		int a, b;
		cin >> a >> b;
		graph[a-1][b-1] = graph[b-1][a-1] = true;
	}
	bool visited[n];
	REP(i, n){ visited[i] = false; }
	visited[0] = true;
	cout << dfs(0, n, visited) << endl;
	return 0;

}