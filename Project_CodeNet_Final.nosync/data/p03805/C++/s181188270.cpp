#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

#define FOR(idx, begin, end) for(int idx = (begin); idx < (end); ++idx)
#define DBG(x) cerr << #x << ": " << x << "\n"

using namespace std;
typedef long long lint;
const int MOD = 1000000007;

int main() {

	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<bool> visited(N, false);
	vector<bool> tmp(N);

	vector<int> a(M), b(M);
	FOR(i, 0, M) cin >> a[i] >> b[i];

	vector<vector<bool>> path(N, vector<bool>(N, false));
	FOR(i, 0, M) {
		path[a[i] - 1][b[i] - 1] = true;
		path[b[i] - 1][a[i] - 1] = true;
	}

	int ans = 0;

	queue<pair<int, vector<bool>>> node;
	copy(visited.begin(), visited.end(), tmp.begin());
	tmp[0] = true;
	node.push({0, tmp});

	while (!node.empty()) {
		
		auto now = node.front();
		node.pop();

		FOR(i, 0, N) {
			if (now.second[i] == false && path[now.first][i] == true) {
				copy(now.second.begin(), now.second.end(), tmp.begin());
				tmp[i] = true;
				node.push({i, tmp});
			}
		}

		FOR(i, 0, N) {
			if (now.second[i] == false) break;
			if (i == N - 1) {
				ans++;
			}
		}
	
	}

	cout << ans;

	return 0;
}