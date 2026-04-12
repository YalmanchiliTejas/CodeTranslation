#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

#define int long long
#define MOD 1000000007

#define rep(i, n) for (int i = 0; i < (n); i++)
#define itrep(i, a) for (auto i = (a).begin(); i != (a).end(); i++)
#define REP(i, a, n) for (int i = (a); i <= (n); i++)
#define all(a) (a).begin(), (a).end()
#define mp(a, b) make_pair((a), (b))

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

class UnionFind {
private:
	vector<int> pastNode;

	class Node {
	public:
		int parent;
		int count;

		Node(int parent) {
			this->parent = parent;
			this->count = 1;
		}
	};

	vector<Node> node;
public:
	UnionFind(int size) {
		for (int i = 0; i < size; i++) {
			node.push_back(Node(i));
		}
	}

	int root(int x) {
		pastNode.clear();

		while (x != node[x].parent) {
			pastNode.push_back(x);
			x = node[x].parent;
		}
		rep(i, pastNode.size()) {
			node[pastNode[i]].parent = x;
		}
		return x;
	}

	void unite(int x, int y) {
		if (root(x) == root(y)) return;

		node[root(y)].count += node[root(x)].count;
		node[root(x)].parent = root(y);
	}

	bool same(int x, int y) {
		return root(x) == root(y);
	}

	int countSames(int x) {
		return node[root(x)].count;
	}
};

signed main() {
	int N;
	cin >> N;

	vector<pair<pair<int, int>, int>> v1, v2;
	rep(i, N) {
		int x, y;
		cin >> x >> y;
		v1.push_back(mp(mp(x, y), i));
		v2.push_back(mp(mp(y, x), i));
	}

	sort(all(v1));
	sort(all(v2));

	priority_queue<pair<int, pair<int, int>>> q;
	rep(i, N - 1) {
		int x1 = v1[i].first.first;
		int y1 = v1[i].first.second;
		int x2 = v1[i + 1].first.first;
		int y2 = v1[i + 1].first.second;
		int dist = min(abs(x2 - x1), abs(y2 - y1));

		q.push(mp(-dist, mp(v1[i].second, v1[i + 1].second)));
	}
	rep(i, N - 1) {
		int x1 = v2[i].first.first;
		int y1 = v2[i].first.second;
		int x2 = v2[i + 1].first.first;
		int y2 = v2[i + 1].first.second;
		int dist = min(abs(x2 - x1), abs(y2 - y1));

		q.push(mp(-dist, mp(v2[i].second, v2[i + 1].second)));
	}

	UnionFind uf(N);

	int ret = 0;
	while (!q.empty()) {
		auto now = q.top(); q.pop();
		int idx1 = now.second.first;
		int idx2 = now.second.second;
		if (uf.same(idx1, idx2)) continue;
		ret += -now.first;
		uf.unite(idx1, idx2);
	}

	cout << ret << endl;
}
