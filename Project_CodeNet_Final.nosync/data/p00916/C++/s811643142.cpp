#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <memory>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cfloat>
#include <cassert>
#include <random>
#include <typeinfo>

struct Square {
	int left, top, right, bottom;
};
class UnionFind {
	std::vector<int> parent;
public:
	UnionFind(int size) : parent(size, -1) {};
	int find(int a) {
		return (parent[a] < 0) ? a : parent[a] = find(parent[a]);
	}
	bool same(int a, int b) {
		return find(a) == find(b);
	}
	void unite(int a, int b) {
		a = find(a); b = find(b);
		if (a != b) {
			if (parent[a] < parent[b]) {
				parent[a] += parent[b];
				parent[b] = a;
			}
			else {
				parent[b] += parent[a];
				parent[a] = b;
			}
		}
	}
	int size() const {
		return parent.size();
	}
};
int main() {
	while (true) {
		int n; std::cin >> n; if (n == 0) break;
		std::vector<Square> squares(n); for (auto& s : squares) std::cin >> s.left >> s.top >> s.right >> s.bottom;
		std::vector<int> horizontal{ -1, 1000001 }, vertical{ -1, 1000001 };
		for (const auto s : squares) {
			horizontal.push_back(s.left); horizontal.push_back(s.right);
			vertical.push_back(s.top); vertical.push_back(s.bottom);
		}
		std::sort(horizontal.begin(), horizontal.end()); std::sort(vertical.begin(), vertical.end());
		horizontal.erase(std::unique(horizontal.begin(), horizontal.end()), horizontal.end()); vertical.erase(std::unique(vertical.begin(), vertical.end()), vertical.end());
		std::unordered_map<int, int> h_map, v_map;
		for (auto i = 0; i < horizontal.size(); ++i) {
			h_map[horizontal[i]] = i;
		}
		for (auto i = 0; i < vertical.size(); ++i) {
			v_map[vertical[i]] = i;
		}
		for (auto& s : squares) {
			s.top = v_map[s.top];
			s.bottom = v_map[s.bottom];
			s.left = h_map[s.left];
			s.right = h_map[s.right];
		}
		std::vector<std::vector<long long int>> state(vertical.size(), std::vector<long long int>(horizontal.size(), 0));
		for (auto i = 0; i < n; ++i) {
			const auto s = squares[i];
			for (auto h = s.bottom; h < s.top; ++h) for (auto v = s.left; v < s.right; ++v) {
				state[h][v] |= 1LL << i;
			}
		}
		UnionFind uft(vertical.size() * horizontal.size());
		for (auto i = 0; i < state.size(); ++i) for (auto j = 0; j < state[i].size(); ++j) {
			if (i > 0 && state[i][j] == state[i - 1][j]) {
				uft.unite(j * state.size() + i, j * state.size() + i - 1);
			}
			if (j > 0 && state[i][j] == state[i][j - 1]) {
				uft.unite(j * state.size() + i, (j - 1) * state.size() + i);
			}
		}
		int result{ 0 };
		for (auto i = 0; i < uft.size(); ++i) {
			if (uft.find(i) == i) ++result;
		}
		std::cout << result << std::endl;
	}
}
