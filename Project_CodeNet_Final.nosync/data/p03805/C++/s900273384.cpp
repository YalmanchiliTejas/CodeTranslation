#include <bits/stdc++.h>
using namespace std;



int find(vector<vector<int>>& nodes, vector<int> footprint, int here, int n) {
	for (int i = 0; i < footprint.size(); i++) {
		if (here == footprint.at(i)) { return 0; }
	}
	footprint.push_back(here);
	if (footprint.size() == n) { return 1; }
	int ret = 0;
	for (int i = 0; i < nodes.at(here).size(); i++) {
		ret += find(nodes, footprint, nodes.at(here).at(i), n);
	}
	return ret;

}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> nodes(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		nodes.at(a-1).push_back(b-1);
		nodes.at(b-1).push_back(a-1);
	}

	int ans = 0;
	vector<int> footprint;
	ans = find(nodes, footprint, 0, n);
	cout << ans << endl;
	return 0;

}
