#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M, a, b, ans = 0;
	cin >> N >> M;
	vector<vector<bool>> c(N, vector<bool>(N));
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		c[a - 1][b - 1] = true;
		c[b - 1][a - 1] = true;
	}
	vector<int> d(N);
	for (int i = 0; i < N; i++) d[i] = i;
	do {
		bool e = true;
		for (int i = 1; i < N; i++) {
			if (!c[d[i - 1]][d[i]]) {
				e = false;
				break;
			}
		}
		if (e) ans++;
	} while (next_permutation(d.begin() + 1, d.end()));
	cout << ans;
}