#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, m, k; cin >> n >> m >> k;
	map<int, int> num_to_ind, ind_to_num;
	vector<bool> dark(n, false);
	for (int i = 0; i < m; ++i) {
		int z; cin >> z; z--;
		num_to_ind[z] = i;
		ind_to_num[i] = z;
		dark[z] = true;
	}
	vector<vector<int> > v(n, vector<int>(k));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			cin >> v[i][j]; v[i][j]--;
		}
	}
	vector<int> dist(1<<m, 10000);
	dist[(1<<m)-1] = 0;
	deque<int> q;
	q.push_back((1<<m)-1);
	while (dist[0] == 10000) {
		int x = q.front();
		q.pop_front();
		for (int i = 0; i < k; ++i) {
			int res = 0;
			for (int j = 0; j < m; ++j) {
				if ((x>>j)&1 && dark[v[ind_to_num[j]][i]]) {
					res |= 1<<(num_to_ind[v[ind_to_num[j]][i]]);
				}
			}
			if (dist[res] > dist[x] + 1) {
				dist[res] = dist[x]+ 1;
				if (res == 0) break;
				q.push_back(res);
			}
		}
	}
	cout << dist[0] << endl;

	return 0;
}
