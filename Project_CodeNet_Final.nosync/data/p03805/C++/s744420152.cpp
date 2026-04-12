# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <ctime>
constexpr int MOD = 1000000007;
constexpr int INF = 2000000000;
using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	vector<int> g[100];
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	vector<int> v;
	for (int i = 0; i < n; i++) {
		v.emplace_back(i + 1);
	}
	int ans = 0;
	do {
		if (v[0] != 1)continue;
		int count = 0;
		for (int i = 0; i < n-1; i++) {
			for (int j = 0; j < g[v[i]].size(); j++) {
				if (g[v[i]][j] == v[i+1] )count++;
			}
		}
		if (count == n - 1)ans++;
	} while (next_permutation(v.begin(), v.end()));
	cout << ans << endl;
}



