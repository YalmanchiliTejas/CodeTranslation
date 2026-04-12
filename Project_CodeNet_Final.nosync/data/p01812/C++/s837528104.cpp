#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
#include <cassert>
#include <unordered_map>

using namespace std;

struct Traversal {
	uint16_t positions;
	int count;

	Traversal(uint16_t initial, int c) : positions(initial), count(c) {}
	Traversal(uint16_t initial) : Traversal(initial, 0) {}
};

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<bool> is_bright_room = vector<bool>(n + 1, true);
	vector<int> dark_rooms;
	// i??????(i????????????)???????????¨?±???????????±????????????????
	uint16_t initial_state = (1 << m) - 1;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		is_bright_room[x] = false;
		dark_rooms.push_back(x);
	}

	vector<vector<int>> edges = vector<vector<int>>(n + 1, vector<int>(k, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			cin >> edges[i][j];
		}
	}

	queue<Traversal> queue;
	queue.emplace(initial_state);
	
	vector<int> dp(1 << m, n * n);
	dp[initial_state] = 0;

	while (!queue.empty()) {
		auto state = queue.front();
		auto positions = state.positions;
		queue.pop();

		for (int j = 0; j < k; j++) {
			uint16_t next_positions = 0;
			for (int i = 0; i < dark_rooms.size(); i++) {
				if (positions & (1 << i)) {
					auto next_position = edges[dark_rooms[i]][j];
					for (int ii = 0; ii < m; ii++) {
						if (dark_rooms[ii] == next_position) {
							next_positions = next_positions | (1 << ii);
						}
					}
				}
			}
			if (dp[next_positions] > state.count + 1) {
				dp[next_positions] = state.count + 1;
				queue.emplace(next_positions, state.count + 1);
			}
		}
	}

	cout << dp[0] << endl;
}