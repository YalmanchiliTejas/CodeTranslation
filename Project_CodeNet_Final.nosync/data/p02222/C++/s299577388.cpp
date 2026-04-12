#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <climits>
#include <numeric>
#include <queue>
#include <cmath>
#include <iomanip>
#include <array>
#include <string>
#include <stack>

int main() {
	int n; std::cin >> n;
	std::vector<std::vector<int>> nodes(n);
	for (auto i = 1; i < n; ++i) {
		int a, b; std::cin >> a >> b;
		nodes[a - 1].push_back(b - 1);
		nodes[b - 1].push_back(a - 1);
	}
	std::stack<int> stack; stack.push(0);
	std::vector<int> depth(n, -1); depth[0] = 1;
	while (!stack.empty()) {
		const auto top = stack.top(); stack.pop();
		for (const auto next : nodes[top]) if (depth[next] == -1) {
			depth[next] = depth[top] + 1;
			stack.push(next);
		}
	}
	const auto end_a = std::distance(depth.begin(), std::max_element(depth.begin(), depth.end()));
	stack.push(end_a);
	depth.assign(n, -1); depth[end_a] = 1;
	std::vector<int> height(n, -1);
	while (!stack.empty()) {
		const auto top = stack.top(); stack.pop();
		if (top >= 0) {
			stack.push(-1 - top);
			for (const auto next : nodes[top]) if (depth[next] == -1) {
				depth[next] = depth[top] + 1;
				stack.push(next);
			}
		}
		else {
			const auto current = -1 - top;
			height[current] = 1;
			for (const auto next : nodes[current]) {
				height[current] = std::max(height[current], height[next] + 1);
			}
		}
	}
	int max{ 2 };
	for (auto i = 0; i < n; ++i) if (nodes[i].size() >= 3) {
		std::vector<int> length; length.reserve(nodes[i].size() + 1);
		std::transform(nodes[i].begin(), nodes[i].end(), std::back_inserter(length), [&depth, &height, i](const int a) {return depth[i] < depth[a] ? height[a] : depth[a]; });
		std::sort(length.rbegin(), length.rend());
		const auto k = length[0] + length[2];
		if (length[0] == length[2]) {
			max = std::max(max, k);
		}
		else {
			max = std::max(max, k + 1);
		}
	}
	for (auto i = 1; i <= n; ++i) {
		if (3 <= i && i < max) {
			std::cout << '0';
		}
		else {
			std::cout << '1';
		}
	}
	std::cout << std::endl;
}

