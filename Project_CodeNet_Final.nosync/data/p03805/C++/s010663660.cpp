#include<bits/stdc++.h>
using namespace std;

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define SORT(c) sort((c).begin(),(c).end())
#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG false

typedef long long ll;
typedef pair<int, int> ii;

int n, m;
vector<vector<int>> g;

int dfs(int n, vector<bool> v){
	int ret = 0;
	v[n] = true;

	bool end = true;
	rep(i, v.size()){
		end &= v[i];
	}
	if(end) return 1;

	rep(i, g[n].size()){
		if(!v[g[n][i]]) ret += dfs(g[n][i], v);
	}

	return ret;
}

int main() {

	cin >> n >> m;
	g.resize(n);

	rep(i, m){
		int p, q;
		cin >> p >> q;
		p--;q--;
		g[p].push_back(q);
		g[q].push_back(p);
	}

	vector<bool> v(n, false);

	cout << dfs(0, v) << endl;

	return 0;
}
