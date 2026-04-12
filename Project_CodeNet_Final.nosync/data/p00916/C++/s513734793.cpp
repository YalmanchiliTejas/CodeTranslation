#include <algorithm>
#include <array>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX_SIZE = 210;
constexpr int INF = (1 << 29);
constexpr array<int, 4> dx{1, -1, 0, 0};
constexpr array<int, 4> dy{0, 0, 1, -1};

int w, h;
long long field[MAX_SIZE][MAX_SIZE];

inline void replace(const vector<int> &coords, vector<int> &target) {
	for(auto &e : target) {
		e = lower_bound(coords.begin(), coords.end(), e) - coords.begin();
		e *= 2;
	}
}

int compress(vector<int> &a, vector<int> &b) {
	vector<int> coords(a);
	coords.reserve(a.size() + b.size() + 2);
	coords.emplace_back(-INF);
	coords.emplace_back(INF);
	coords.insert(coords.end(), b.begin(), b.end());

	sort(coords.begin(), coords.end());
	coords.erase(unique(coords.begin(), coords.end()), coords.end());

	replace(coords, a);
	replace(coords, b);

	return coords.size() * 2;
}

inline bool out(int x, int y) {
	return x < 0 || y < 0 || x >= w || y >= h;
}

void dfs(int x, int y, long long value) {
	field[y][x] = -1;
	for(int i = 0; i < 4; ++i) {
		const int nx = x + dx[i];
		const int ny = y + dy[i];

		if(out(nx, ny) || field[ny][nx] != value) continue;
		dfs(nx, ny, value);
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	for(int n; cin >> n && n;) {
		vector<int> l(n), t(n), r(n), b(n);
		for(int i = 0; i < n; ++i) {
			cin >> l[i] >> t[i] >> r[i] >> b[i];
		}

		w = compress(l, r);
		h = compress(t, b);

		for(int i = 0; i < n; ++i) {
			--t[i];
			++l[i];
		}

		memset(field, 0, sizeof(field));
		for(int i = 0; i < n; ++i) {
			long long bit = (1ll << i);
			field[t[i]][l[i]] += bit;
			field[t[i]][r[i] + 1] -= bit;
			field[b[i] - 1][l[i]] -= bit;
			field[b[i] - 1][r[i] + 1] += bit;
		}

		for(auto &line : field) {
			partial_sum(begin(line), end(line), begin(line));
		}

		for(int y = h - 1; y > 0; --y) {
			for(int x = 0; x < w; ++x) {
				field[y - 1][x] += field[y][x];
			}
		}

		int ans = 0;
		for(int i = 0; i < h; ++i) {
			for(int j = 0; j < w; ++j) {
				if(field[i][j] != -1) {
					dfs(j, i, field[i][j]);
					++ans;
				}
			}
		}
		cout << ans << endl;
	}
	return EXIT_SUCCESS;
}