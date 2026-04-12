
// C - One-stroke Path

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

struct Node {
	vector<int> neighbor;
};

int N, M;
int ans = 0;
vector<Node> nodes;

void search(int node_idx, unordered_set<int> visited) {
	visited.insert(node_idx);

	if (visited.size() == N) {
		ans++;
		return;
	}

	for (int next_node_idx : nodes[node_idx].neighbor) {
		if (visited.find(next_node_idx) == visited.end()) {
			// 未訪問なら探索
			search(next_node_idx, visited);
		}
	}
}

int main() {
	cin >> N >> M;

	nodes = vector<Node>(N);

	int a, b;
	for (int i=0; i<M; i++) {
		cin >> a >> b;
		a--;
		b--;
		nodes[a].neighbor.push_back(b);
		nodes[b].neighbor.push_back(a);
	}

	unordered_set<int> visited;
	search(0, visited);

	cout << ans << endl;

	return 0;
}