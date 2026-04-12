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

	queue<vector<int>> roots;
	roots.push(vector<int>{ 0 });

	int cnt = 0;
	while (!roots.empty()) {
		auto root = roots.front();
		roots.pop();

		for (int val : arr[root.back()]) {
			if (find(root.begin(), root.end(), val) == root.end()) {
				vector<int> newRoot(root);
				newRoot.push_back(val);

				if (newRoot.size() == N)
					cnt++;
				else
					roots.push(newRoot);
			}
		}
	}

	cout << cnt << endl;

	return 0;
}

