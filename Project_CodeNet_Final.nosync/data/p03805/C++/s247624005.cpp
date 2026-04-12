#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> P;
vector<vector<bool> > G;

int main(void) {
	cin >> N >> M;
	vector<bool> v;
	v.resize(N + 1, false);
	G.resize(N + 1, v);
	for (int i = 1; i <= M; ++i) {
		int a, b;
		cin >> a >> b;
		G[a][b] = true;
		G[b][a] = true;
	}

	int ans = 0;
	P.resize(N - 1);
	for (int i = 2; i <= N; ++i)
		P.push_back(i);
	do {
		int s = 1;
		bool flag = true;
		for (int i = 0; i <= N - 2; ++i) {
			int t = P[i];
			if (G[s][t] != true) {
				flag = false;
				break;
			}
			s = t;
		}
		if (flag)
			++ans;
	} while (next_permutation(P.begin(), P.end()));

	cout << ans << '\n';
	return 0;
}
