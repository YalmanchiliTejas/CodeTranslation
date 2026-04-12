#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define rep(i, n)	for(int i = 0; i < (int)(n); i++)

struct Node {
	vector<int> link;
	bool passed = false;
};

Node nodes[9];
vector<int> route;
int N, M;



int main() {
	int ans = 0;

	cin >> N >> M;

	// 順列用
	for (int i = 0; i < N; i++) {
		route.push_back(i + 1);
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		nodes[a].link.push_back(b);
		nodes[b].link.push_back(a);
	}

	do {
		for (int i = 1; i <= N; i++) {
			nodes[i].passed = false;
		}


		bool flag = true;
		for (size_t r = 0, length = route.size(); r < length; ++r) {

			if (route[r] != route[length - 1]) {
				if (nodes[route[r]].passed || find(nodes[route[r]].link.begin(), nodes[route[r]].link.end(), route[r + 1]) == nodes[route[r]].link.end()) {
					flag = false;
					break;
				}
			}

			nodes[route[r]].passed = true;
		}

		if (flag) ans++;

	} while (next_permutation(route.begin() + 1, route.end()));

	cout << ans << endl;

	return 0;
}