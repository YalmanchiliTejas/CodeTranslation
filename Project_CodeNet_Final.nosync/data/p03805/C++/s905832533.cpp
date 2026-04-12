//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#define INF 2147483647
#define lli long long int
#define MOD 1000000007
#define pb push_back

using namespace std;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;

vvi edge(8,vi(8,0));

bool check(vi u) {
	for (int i = 0; i < u.size(); i++) {
		if (u[i] == 0) return false;
	}
	return true;
}
int dfs(vi used,int node) {
	if (check(used)) return 1;
	
	int res = 0;

	for (int i = 0; i < used.size(); i++) {
		if (edge[node][i] == 0) continue;
		if (used[i] == 1) continue;
		used[i] = 1;
		res += dfs(used,i);
		used[i] = 0;
	}

	return res;

}

int main() {

	int n,m; cin >> n >> m;
	vi used(n,0);

	for (int i = 0; i < m; i++) {
		int a,b; cin >> a >> b;
		edge[a-1][b-1] = 1;
		edge[b-1][a-1] = 1;
	}
	used[0] = 1;	
	cout << dfs(used,0) << endl;
	

	return 0;
}



