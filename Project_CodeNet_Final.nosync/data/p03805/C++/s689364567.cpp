#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<bool>> path(N, vector<bool>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			path[i][j] = false;
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		path[a-1][b-1] = true;
		path[b-1][a-1] = true;
	}

	vector<int> perm(N-1);
	for (int i = 0; i < N - 1; i++) perm[i] = i + 1;
	int ans = 0;
	do {
		if (!path[0][perm[0]]) continue;
		int flag = true;
		for (int i = 0; i < N - 2; i++) {
			if (!path[perm[i]][perm[i+1]]) {
				flag = false;
				break;
			}
		}
		if (flag) ans++;
	} while (next_permutation(perm.begin(), perm.end()));
	cout << ans << endl;
}
