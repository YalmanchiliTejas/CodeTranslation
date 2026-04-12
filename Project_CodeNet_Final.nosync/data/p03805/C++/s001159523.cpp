
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
unordered_set<int> visited;

void search(int node_idx) {
	if (visited.size() == N) {
		ans++;
		return;
	}

	for (int next_node_idx : nodes[node_idx].neighbor) {
		// 未訪問なら探索
		if (visited.find(next_node_idx) == visited.end()) {
			visited.insert(next_node_idx); // 訪問済みにする
			search(next_node_idx);
			visited.erase(next_node_idx); // 探索が終わったら未訪問に戻す
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

	visited.insert(0);
	search(0);

	cout << ans << endl;

	return 0;
}