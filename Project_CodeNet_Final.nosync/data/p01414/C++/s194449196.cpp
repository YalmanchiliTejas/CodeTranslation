#include <bits/stdc++.h>

#ifdef LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif

using namespace std;

#define REP(i, a, b) for(int i = (a); i < int(b); ++i)
#define rep(i, n) REP(i, 0, n)
#define ALL(x) begin(x), end(x)

constexpr int SIZE = 4;
enum { R, G, B, NUM_COLORS };

int bfs(const array<int, NUM_COLORS> &colors, const vector<int> &stamps) {
	constexpr int ARRAY_SIZE = 1 << (SIZE * SIZE);
	constexpr int goal = ARRAY_SIZE - 1;

	queue<int> que;
	array<int, ARRAY_SIZE> dist;

	que.push(0);
	dist.fill(INT_MAX);
	dist[0] = 0;

	while(!que.empty()) {
		const int v = que.front();
		que.pop();

		for(const auto &s : stamps) {
			for(const auto &c : colors) {
				const int to = (v & ~s) | (c & s);

				if(dist[to] == INT_MAX) {
					if(to == goal) return dist[v] + 1;
					que.push(to);
					dist[to] = dist[v] + 1;
				}
			}
		}
	}
	assert(false);
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int convert[128];
	convert[static_cast<int>('R')] = R;
	convert[static_cast<int>('G')] = G;
	convert[static_cast<int>('B')] = B;

	int n;
	cin >> n;

	vector<int> stamps;
	stamps.reserve(n * (2 * SIZE - 1) * (2 * SIZE - 1));

	rep(idx, n) {
		int h, w;
		cin >> h >> w;

		REP(dx, -SIZE + 1, SIZE) {
			REP(dy, -SIZE + 1, SIZE) {
				int bit = 0;

				rep(i, h) {
					const int y = i + dy;
					if(y < 0 || y >= SIZE) continue;

					rep(j, w) {
						const int x = j + dx;
						if(x < 0 || x >= SIZE) continue;

						bit |= (1 << (y * SIZE + x));
					}
				}

				stamps.emplace_back(bit);
			}
		}
	}

	sort(ALL(stamps));
	stamps.erase(unique(ALL(stamps)), end(stamps));

	array<int, NUM_COLORS> colors;
	colors.fill(0);

	rep(i, SIZE) {
		string row;
		cin >> row;

		rep(j, SIZE) {
			colors[convert[static_cast<int>(row[j])]] |= (1 << (i * SIZE + j));
		}
	}

	cout << bfs(colors, stamps) << endl;

	return EXIT_SUCCESS;
}