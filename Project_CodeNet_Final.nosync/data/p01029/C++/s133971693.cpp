#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=a;i<b;++i)
#define allof(a) a.begin(),a.end()
#define minit(a,b) memset(a,b,sizeof(a))
#define size_of(a) (int)a.size()

typedef long long lint;
typedef pair<int, int> pii;

int V, E;
char ans[100010];
vector< vector<int> > edges;

set<char> cand[100010];

void solve() {
	for_(i,0,V) {
		cand[i].clear();
		if (ans[i] != '?') continue;
		for_(j,0,26) {
			cand[i].insert('a' + j);
		}
	}
	
	for_(i,0,V) {
		if (ans[i] != '?') {
			int e_size = size_of(edges[i]);
			for_(j,0,e_size) {
				int u = edges[i][j];
				cand[u].erase(ans[i]);
			}
		}
	}
	
	for_(i,0,V) {
		if (ans[i] == '?') {
			char c = *cand[i].begin();
			ans[i] = c;
			int e_size = size_of(edges[i]);
			for_(j,0,e_size) {
				int u = edges[i][j];
				cand[u].erase(c);
			}
		}
		
		cout << ans[i];
	}
	cout << endl;
}

int main() {
	cin >> V >> E;
	for_(i,0,V) {
		char c; cin >> c;
		ans[i] = c;
	}
	edges.assign(V, vector<int>());
	for_(i,0,E) {
		int s, t; cin >> s >> t;
		edges[s].push_back(t);
		edges[t].push_back(s);
	}
	solve();
	return 0;
}
