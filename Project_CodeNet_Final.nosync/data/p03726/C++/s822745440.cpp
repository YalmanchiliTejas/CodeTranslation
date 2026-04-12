#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> pip;

struct HASH {
	size_t operator() (const pair<int,int> &x) const {
		return hash <long long> () (((long long)x.first) ^ (((long long)x.second) << 32));
	}
};

const int MAX_N = 1e5 + 5;
int n;
vector <pip> G[MAX_N];
unordered_map <pii, int, HASH> Map;

void calc(int v, int u, int type) {
	if (type == 1) {
		G[v][Map[{u, v}]].second.first = 1;
		
		for (int i = 0; i < G[v].size(); i++)
			if (G[v][i].first != u) {
				int k = G[v][i].first;
				int ind = Map[{v, k}];
				if (!G[k][ind].second.second)
					calc(k, v, 2);
				
				if (G[k][ind].second.second == 2) {
					G[v][Map[{u, v}]].second.first = 2;
					break;
				}
			}
		
		return ;
	}
	G[v][Map[{u, v}]].second.second = 2;
	for (int i = 0; i < G[v].size(); i++)
		if (G[v][i].first != u) {
			int k = G[v][i].first;
			int ind = Map[{v, k}];
			if (!G[k][ind].second.first)
				calc(k, v, 1);
			
			if (G[k][ind].second.first == 1) {
				G[v][Map[{u, v}]].second.second = 1;
				break;
			}
		}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int v, u;
		cin >> v >> u;
		v--; u--;
		Map[{v, u}] = G[u].size();
		Map[{u, v}] = G[v].size();
		G[v].push_back({u, {0, 0}});
		G[u].push_back({v, {0, 0}});
	}
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < G[i].size(); j++) {
			if (!G[i][j].second.first)
				calc(i, G[i][j].first, 1);
			
			if (!G[i][j].second.second)
				calc(i, G[i][j].first, 2);
		}
	
	for (int i = 0; i < n; i++) {
		bool can = true;
		for (int j = 0; j < G[i].size(); j++) {
			int v = G[i][j].first;
			int ind = Map[{i, v}];
			
			if (G[v][ind].second.first == 1) {
				can = false;
				break;
			}
		}
		
		if (can) {
			cout << "First\n";
			return 0;
		}
	}
	
	cout << "Second\n";
	return 0;
}