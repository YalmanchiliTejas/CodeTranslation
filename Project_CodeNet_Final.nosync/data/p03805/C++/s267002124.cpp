#include "bits/stdc++.h"

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//using Matrix = vector< vector<int> >;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1 << 30;
int dx[5] = {0, 0, 1, -1, 0}, dy[5] = {1, -1, 0, 0, 0};

vector<int> G[10];
set<int> check;
bool path;
int cnt;

int n, m;

void debug(void) {
	cout<<endl;
	for(int i=0;i<n;i++) {
		for(int j=0;j<G[i].size();j++) {
			cout<<G[i][j]<<" ";
		}cout<<endl;
	}cout<<endl;

	return ;
}

void dfs(int v, set<int> check) {
	check.insert(v);
	if(check.size() == n) {
		cnt++;
		return ;
	}

	for(int j=0;j<G[v].size();j++) {
		if(check.count(G[v][j])) continue;

		dfs(G[v][j], check);
	}

	return ;
}

int main(void){
	cin>>n>>m;
	for(int i=0;i<m;i++) {
		int a, b; cin>>a>>b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	//debug();

	dfs(0, check);
	//for(int i=0;i<G[0].size();i++) {
	//	dfs(G[0][i]);
	//}

	cout<< cnt <<endl;

	return 0;
}