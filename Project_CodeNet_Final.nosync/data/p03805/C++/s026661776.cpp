#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> g;
	g.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<int> v;
	for (int i = 1; i <= N; i++)
		v.push_back(i);

	int ans = 0;
	do {
		if (v[0] == 1) {
			bool canGo = true;
			for (int i = 0; i < v.size() - 1; i++) {
				if (find(g[v[i]].begin(), g[v[i]].end(), v[i + 1]) == g[v[i]].end())
					canGo = false;
			}
			if (canGo)
				ans++;
		}
	} while (next_permutation(v.begin(), v.end()));

	cout << ans << endl;

	return 0;
}