#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	map<int,int> D;
	for (int i=0; i<M; ++i) {
		int d;
		cin >> d;
		D[d-1] = i;
	}
	vector<vector<int>> to(M);
	for (int i=0; i<N; ++i) {
		for (int j=0; j<K; ++j) {
			int v;
			cin >> v;
			if (D.count(i)) {
				to[D[i]].push_back(D.count(v-1) ? D[v-1] : -1);
			}
		}
	}

	vector<int> cost(1<<M, 1e8);
	queue<pair<int,int>> q; // (移動回数,ビット状態)
	q.emplace(0, (1<<M)-1);
	int t, bt;
	while ( ! q.empty()) {
		tie(t, bt) = q.front();
		q.pop();
		if ( ! bt) break;
		if (cost[bt] <= t) continue;
		cost[bt] = t;
		for (int i=0; i<K; ++i) {
			int bt2 = 0;
			for (int j=0; j<M; ++j) {
				if (~to[j][i] && ((bt>>j)&1)) {
					bt2 |= (1<<to[j][i]);
				}
			}
			q.push(make_pair(t+1, bt2));
		}
	}
	cout << t << endl;
}
