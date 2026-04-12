#include <iostream>
// #include <iomanip>
// #include <vector>
#include <algorithm>
// #include <cmath>
// #include <utility>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int N;
pair<int, int> x[100000];
pair<int, int> y[100000];

int calc() {
	unordered_multimap<int, pair<int, int>> edges;	// 全辺（双方向）
	unordered_set<int> visited;					// 訪問済み点
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> candidates;	// 訪問済み点から延びる辺

	sort(x, x + N);
	sort(y, y + N);
	for (int i = 0; i < N - 1; i++) {
		edges.insert(make_pair(x[i].second, make_pair(x[i + 1].first - x[i].first, x[i + 1].second)));
		edges.insert(make_pair(x[i + 1].second, make_pair(x[i + 1].first - x[i].first, x[i].second)));
		edges.insert(make_pair(y[i].second, make_pair(y[i + 1].first - y[i].first, y[i + 1].second)));
		edges.insert(make_pair(y[i + 1].second, make_pair(y[i + 1].first - y[i].first, y[i].second)));
	}
	long long answer = 0;

	visited.insert(0);
	auto range = edges.equal_range(0);
	for (auto itr = range.first; itr != range.second; itr++) {
		candidates.push(itr->second);
	}

	while (visited.size() < N) {
		pair<int, int> edge = candidates.top();
		candidates.pop();
		// cout << "edge to " << edge.second << " : " << edge.first << endl;
		if (visited.insert(edge.second).second) { // 挿入成功
			answer += edge.first;
			auto range = edges.equal_range(edge.second);
			for (auto itr = range.first; itr != range.second; itr++) {
				candidates.push(itr->second);
			}
			// cout << "\tAdded" << endl;
		}
	}

	return answer;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x[i].first >> y[i].first;
		x[i].second = i;
		y[i].second = i;
	}
	cout << calc() << endl;
}