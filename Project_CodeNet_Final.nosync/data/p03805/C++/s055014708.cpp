#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	auto edge = vector<vector<int>>(10,vector<int>(10,0));
	for (int i = 0; i < m;++i) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		edge[a][b] = edge[b][a] = 1;
	}
	vector<int> order;
	for (int i = 0; i < n; ++i) {
		order.push_back(i);
	}
	int sum = 0;
	do {
		bool flag = true;
		if (order[0] != 0) continue;
		for (int i = 0; i + 1 < n; ++i) {
			if (edge[order[i]][order[i + 1]] == 0) {
				flag = false;
			}
		}
		if (flag) sum++;
	} while (next_permutation(order.begin(), order.end()));
	cout << sum << endl;
	return 0;
}