#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

template<class T> inline void chmax(T &a, const T &b) { if(a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if(a > b) a = b; }

constexpr int INF = (1 << 29);

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m, w, t;
	cin >> n >> m >> w >> t;

	unordered_map<string, int> converter;
	vector<int> v(m), p(m);

	for(int i = 0; i < m; ++i) {
		string name;
		cin >> name >> v[i] >> p[i];
		converter[name] = i;
	}

	vector<vector<int>> value(n, vector<int>(m, 0));
	vector<int> x(n), y(n);

	for(int i = 0; i < n; ++i) {
		int l;
		cin >> l >> x[i] >> y[i];

		while(l--) {
			string name;
			int q;
			cin >> name >> q;

			const int idx = converter[name];
			chmax(value[i][idx], p[idx] - q);
		}
	}

	const int mask = (1 << n) - 1;
	vector<int> dist(1 << n, INF);
	vector<vector<int>> tsp(n, vector<int>(1 << n, INF));

	for(int i = 0; i < n; ++i) {
		tsp[i][1 << i] = abs(x[i]) + abs(y[i]);
	}

	for(int bit = 1; bit < (1 << n); ++bit) {
		for(int shop = 0; shop < n; ++shop) {
			if(!(bit & (1 << shop))) continue;
			chmin(dist[bit], tsp[shop][bit] + abs(x[shop]) + abs(y[shop]));

			for(int to = 0; to < n; ++to) {
				if(bit & (1 << to)) continue;
				chmin(tsp[to][bit | (1 << to)], tsp[shop][bit] + abs(x[to] - x[shop]) + abs(y[to] - y[shop]));
			}
		}
	}

	vector<long long> dp(t + 1, 0);

	for(int bit = 1; bit < (1 << n); ++bit) {
		vector<int> max_value(w + 1, 0);

		for(int shop = 0; shop < n; ++shop) {
			if(!(bit & (1 << shop))) continue;

			for(int i = 0; i < m; ++i) {
				if(value[shop][i] == 0) continue;

				for(int j = 0; j <= w - v[i]; ++j) {
					chmax(max_value[j + v[i]], max_value[j] + value[shop][i]);
				}
			}
		}

		const int tmp = *max_element(begin(max_value), end(max_value));
		for(int i = 0; i <= t - dist[bit]; ++i) {
			chmax(dp[i + dist[bit]], dp[i] + tmp);
		}
	}

	cout << *max_element(begin(dp), end(dp)) << endl;

	return EXIT_SUCCESS;
}