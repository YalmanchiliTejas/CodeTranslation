#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <tuple>
#include <bitset>
#include <memory>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cfloat>
#include <random>



class Seg {
	mutable std::vector<std::vector<std::vector<int>>> count;
	mutable std::vector<std::vector<std::vector<int>>> change;
	int inner_count(const int depth, const int from, const int until, const int brightness_lower, const int brightness_upper) const {
		if (from >= until) return 0;
		const int length = 1 << depth;
		const int mid = (from + length - 1) / length * length;
		if (mid + length <= until) {
			return count_seg(depth, mid / length, brightness_lower, brightness_upper) + inner_count(depth, from, mid, brightness_lower, brightness_upper) + inner_count(depth, mid + length, until, brightness_lower, brightness_upper);
		}
		else if (from < mid && mid < until) {
			return inner_count(depth, from, mid, brightness_lower, brightness_upper) + inner_count(depth, mid, until, brightness_lower, brightness_upper);
		}
		else {
			apply_change(depth, from / length);
			return inner_count(depth - 1, from, until, brightness_lower, brightness_upper);
		}
	}
	int count_seg(const int depth, const int position, const int brightness_lower, const int brightness_upper) const {
		int result = 0;
		for (auto i = 0; i < count[depth][position].size(); ++i) {
			if (brightness_lower <= change[depth][position][i] && change[depth][position][i] <= brightness_upper) result += count[depth][position][i];
		}
		return result;
	}
	void apply_change(const int depth, const int position) const {
		if (change[depth].size() <= position) return;
		for (auto i = 0; i < 10; ++i) {
			change[depth - 1][position * 2][i] = change[depth][position][change[depth - 1][position * 2][i]];
			change[depth - 1][position * 2 + 1][i] = change[depth][position][change[depth - 1][position * 2 + 1][i]];
			count[depth][position][i] = 0;
		}

		for (auto i = 0; i < 10; ++i) {
			change[depth][position][i] = i;
			count[depth][position][change[depth - 1][position * 2][i]] += count[depth - 1][position * 2][i];
			count[depth][position][change[depth - 1][position * 2 + 1][i]] += count[depth - 1][position * 2 + 1][i];
		}
	}
	void inner_update(const int depth, const int from, const int until, const int brightness_from, const int brightness_to) {
		if (from >= until) return;
		const int length = 1 << depth;
		const int mid = (from + length - 1) / length * length;
		if (mid + length <= until) {
			for (auto i = 0; i < 10; ++i) {
				if (change[depth][mid / length][i] == brightness_from) change[depth][mid / length][i] = brightness_to;
			}
			inner_update(depth, from, mid, brightness_from, brightness_to);
			inner_update(depth, mid + length, until, brightness_from, brightness_to);
		}
		else if (from < mid && mid < until) {
			inner_update(depth, from, mid, brightness_from, brightness_to);
			inner_update(depth, mid, until, brightness_from, brightness_to);
		}
		else {
			apply_change(depth, from / length);
			inner_update(depth - 1, from, until, brightness_from, brightness_to);
			accumulate(depth, from / length);
		}
	}
	void accumulate(const int depth, const int position) {
		if (depth == 0 || position >= count[depth].size()) return;
		for (auto i = 0; i < 10; ++i) count[depth][position][i] = 0;
		for (auto i = 0; i < 10; ++i) {
			count[depth][position][change[depth - 1][position * 2][i]] += count[depth - 1][position * 2][i];
			count[depth][position][change[depth - 1][position * 2 + 1][i]] += count[depth - 1][position * 2 + 1][i];
		}
	}
public:
	Seg(const int size) : count{ std::vector<std::vector<int>>(size, std::vector<int>(10, 0)) }, change{ std::vector<std::vector<int>>(size, std::vector<int>(10, 0)) } {
		for (auto i = 0; i < size; ++i) {
			count[0][i][0] = 1;
			for (auto j = 0; j < 10; ++j) {
				change[0][i][j] = j;
			}
		}
		while (count.back().size() > 1) {
			count.emplace_back(count.back().size() / 2, std::vector<int>(10, 0));
			change.emplace_back(change.back().size() / 2, std::vector<int>(10, 0));
		}
		for (auto d = 1; d < count.size(); ++d) {
			for (auto i = 0; i < count[d].size(); ++i) {
				for (auto j = 0; j < 10; ++j) {
					count[d][i][j] = count[d - 1][i * 2][j] + count[d - 1][i * 2 + 1][j];
					change[d][i][j] = j;
				}
			}
		}
	}
	int count_up(int from, int until, int bright_lower, int bright_upper) const {
		return inner_count(count.size() - 1, from, until, bright_lower, bright_upper);
	}
	void change_brightness(int from, int until, int bright_from, int bright_to) {
		inner_update(change.size() - 1, from, until, bright_from, bright_to);
	}
};
struct Range { int from, until; };
int main() {
	int n, q; std::cin >> n >> q;
	std::vector<std::vector<int>> lights(n);
	for (auto i = 1; i < n; ++i) {
		int u, v; std::cin >> u >> v;
		lights[u].push_back(v);
	}
	std::vector<Range> ranges(n, { -1, -1 });
	std::stack<int> stack; stack.push(0);
	for (auto i = 0; i <= n; ++i) {
		while (!stack.empty() && ranges[stack.top()].from != -1) {
			ranges[stack.top()].until = i;
			stack.pop();
		}
		if (!stack.empty()) {
			auto top = stack.top();
			ranges[top].from = i;
			for (const auto child : lights[top]) {
				stack.push(child);
			}
		}
	}
	Seg seg(n);
	for (auto i = 0; i < q; ++i) {
		int t, r, x, y; std::cin >> t >> r >> x >> y;
		switch (t) {
		case 1: std::cout << seg.count_up(ranges[r].from, ranges[r].until, x, y) << '\n'; break;
		case 2: seg.change_brightness(ranges[r].from, ranges[r].until, x, y); break;
		default: throw "???";
		}
	}
}
