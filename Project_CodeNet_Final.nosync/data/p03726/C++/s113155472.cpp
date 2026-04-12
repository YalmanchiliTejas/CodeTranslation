#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
#include <map>

using namespace std;

void show(set<int> &s) {
	for (auto e : s) {
		cout << e << " ";
	}
	cout << endl;
}

void show(map<int, set<int>> &m) {
	for (auto p : m) {
		cout << p.first << ": ";
		show(p.second);
	}
}

int main() {
	int n, a, b;
	cin >> n;

	map<int, set<int>> connect;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		connect[a].insert(b);
		connect[b].insert(a);
	}

	set<int> leaves;
	for (auto p : connect) {
		if (p.second.size() == 1) {
			leaves.insert(p.first);
		}
	}

// cout << "leaf: ";
// show(leaves);
// show(connect);

	while (!leaves.empty()) {
// cout << "leaf: ";
// show(leaves);

		int leaf = *leaves.begin();
		leaves.erase(leaf);

		int leaf_next = *connect[leaf].begin();
		connect.erase(leaf);

		auto next_nexts = connect[leaf_next];
		connect.erase(leaf_next);
// printf("%d - %d - \n", leaf, leaf_next);
// cout << "next_nexts: ";
// show(next_nexts);

		for (auto x : next_nexts) {
// cout << "erase " << x << endl;
			connect[leaf_next].erase(x);
			if (x == leaf) {
// cout << "erase leaf " << x << endl;
				continue;
			}
			connect[x].erase(leaf_next);
// show(connect);
			if (connect[x].size() == 0) {
				cout << "First" << endl;
				return 0;
			} else if (connect[x].size() == 1) {
				leaves.insert(x);
			}
		}
	}

	cout << "Second" << endl;
	return 0;
}
