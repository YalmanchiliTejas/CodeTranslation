#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int path[8][8] = { 0 };
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		path[a - 1][b - 1] = 1;
		path[b - 1][a - 1] = 1;
	}
	vector<int> x;
	for (int i = 0; i < N; i++) {
		x.push_back(i);
	}
	int ans = 0;
	do {
		bool flag = true;
		for (int i = 1; i < x.size(); i++) {
			if (path[x[i - 1]][x[i]] == 0) {
				flag = false;
				break;
			}
		}
		if (flag)ans++;
	} while (next_permutation(x.begin() + 1, x.end()));
	cout << ans << endl;
	return 0;
}