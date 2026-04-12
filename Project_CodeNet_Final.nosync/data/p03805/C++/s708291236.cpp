#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int N, M, a, b;
	cin >> N >> M;

	vector<vector<int>> arr(N);
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		arr[a - 1].push_back(b - 1);
		arr[b - 1].push_back(a - 1);
	}

	queue<vector<bool>> roots;
	queue<int> nexts;
	roots.push(vector<bool>(N));
	nexts.push(0);

	int cnt = 0;
	while (!roots.empty()) {
		auto root = roots.front();
		roots.pop();
		int next = nexts.front();
		nexts.pop();

		vector<bool> newRoot(root);
		newRoot[next] = true;
		bool allVisited = true;
		for (int i = 0; i < newRoot.size(); i++) {
			if (!newRoot[i]) {
				allVisited = false;
				break;
			}
		}
		if (allVisited)
			cnt++;
		else {
			for (int val : arr[next]) {
				if (!root[val]) {
					roots.push(newRoot);
					nexts.push(val);
				}
			}
		}
	}

	cout << cnt << endl;

	return 0;
}

