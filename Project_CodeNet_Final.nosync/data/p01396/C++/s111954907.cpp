#include <iostream>
#include <vector>
#include <array>
#include <list>
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
#include <cassert>
#include <random>

struct Edge {
	int to;
	bool has_flow;
	Edge* pair = nullptr;
};
void bfs(const std::vector<std::vector<Edge>>& nodes, const int source, std::queue<int>& queue, std::vector<int>& depth) {
	std::fill(depth.begin(), depth.end(), -1); depth[source] = 0;
	queue.push(source);
	while (!queue.empty()) {
		auto top = queue.front(); queue.pop();
		for (const auto& e : nodes[top]) if (depth[e.to] == -1 && e.has_flow) {
			depth[e.to] = depth[top] + 1;
			queue.push(e.to);
		}
	}
}
bool dfs(std::vector<std::vector<Edge>>& nodes, const int current, const int sink, std::vector<int> &searching, const std::vector<int> & depth) {
	if (current == sink) return true;
	while (searching[current] < nodes[current].size()) {
		auto& e = nodes[current][searching[current]++];
		if (e.has_flow && depth[current] < depth[e.to] && dfs(nodes, e.to, sink, searching, depth)) {
			--searching[current];
			e.has_flow = false;
			e.pair->has_flow = true;
			return true;
		}
	}
	return false;
}
int cal_max_flow(std::vector<std::vector<Edge>> &nodes, const int source, const int sink) {
	std::vector<int> depth(nodes.size()), searching(nodes.size(), 0);
	std::queue<int> queue;
	int count = 0;
	bool has_flow = true;
	while (has_flow) {
		has_flow = false;
		bfs(nodes, source, queue, depth);
		std::fill(searching.begin(), searching.end(), 0);
		while (dfs(nodes, source, sink, searching, depth)) {
			++count;
			has_flow = true;
		}
	}
	return count;
}
void add_edge(std::vector<std::vector<Edge>>& node, const int from, const int to) {
	node[from].push_back(Edge{ to, true });
	node[to].push_back(Edge{ from, false });
	node[from].back().pair = &node[to].back();
	node[to].back().pair = &node[from].back();
}
bool can_make(const std::vector<std::vector<int>> edges) {
	const auto source = edges.size() * 2;
	const auto sink = source + 1;
	std::vector<std::vector<Edge>> nodes(sink + 1);
	for (auto i = 0; i < edges.size(); ++i) {
		if (edges[i].size() == edges.size() - 1) {
			nodes[i].reserve(edges[i].size() + 2);
			nodes[i + edges.size()].reserve(edges.size() + 1);
		}
		else {
			nodes[i].reserve(edges[i].size() + 1);
			nodes[i + edges.size()].reserve(edges.size() + 1);
		}
	}
	nodes[source].reserve(edges.size() + 1);
	nodes[sink].reserve(edges.size());
	for (auto i = 0; i < edges.size(); ++i) {
		for (const auto j : edges[i]) {
			add_edge(nodes, i, j + edges.size());
		}
		if (edges[i].size() == edges.size() - 1) add_edge(nodes, source, i);
		add_edge(nodes, source, i);
		add_edge(nodes, i + edges.size(), sink);
	}
	return cal_max_flow(nodes, source, sink) == edges.size() - 1;
}
int main() {
	int h, w; std::cin >> h >> w;
	std::vector<std::vector<int>> state(h, std::vector<int>(w));
	for (auto& line : state) for (auto& cell : line) std::cin >> cell;
	std::vector<std::vector<int>> row(h), column(w);
	std::vector<int> row_indices(h), column_indices(w); std::iota(row_indices.begin(), row_indices.end(), 0); std::iota(column_indices.begin(), column_indices.end(), 0);
	std::sort(row_indices.begin(), row_indices.end(), [&state](int i, int j) {return state[i][0] > state[j][0]; });
	std::sort(column_indices.begin(), column_indices.end(), [&state](int i, int j) {return state[0][i] > state[0][j]; });
	for (auto r1 = 0; r1 < h; ++r1) {
		for (auto r2 = r1 + 1; r2 < h; ++r2) {
			bool has_edge = true;
			for (auto c = 1; c < w; ++c) {
				if (state[row_indices[r1]][c] < state[row_indices[r2]][c]) {
					has_edge = false;
					break;
				}
			}
			if (has_edge) row[row_indices[r1]].push_back(row_indices[r2]);
		}
	}
	for (auto c1 = 0; c1 < w; ++c1) {
		for (auto c2 = c1 + 1; c2 < w; ++c2) {
			bool has_edge = true;
			for (auto r = 0; r < h; ++r) {
				if (state[r][column_indices[c1]] < state[r][column_indices[c2]]) {
					has_edge = false;
					break;
				}
			}
			if (has_edge) column[column_indices[c1]].push_back(column_indices[c2]);
		}
	}
	if (can_make(row) && can_make(column)) {
		std::cout << "YES\n";
	}
	else {
		std::cout << "NO\n";
	}
}

