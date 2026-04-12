#include<bits/stdc++.h>
using namespace std;

using lint = long long;

int main() {
	lint N, X, M;
	cin >> N >> X >> M;

	vector<lint> beki(M, 0);
	for (int i = 0; i < M; i++) beki[i] = (lint)i * i % M;

	if (N <= 10000000) {
		lint ans = 0;
		lint now = X;
		for (int i = 0; i < N; i++) {
			ans += now;
			now = beki[now];
		}
		cout << ans << endl;
		return 0;
	}

	vector<int> visited(M, 0);
	lint now = X;
	while (1) {
		visited[now]++;
		if (visited[now] == 3) {
			int cnt1 = 0, cnt2 = 0, cnt3 = 0;
			for (int i = 0; i < M; i++) {
				if (visited[i] == 1) cnt1++;
				else if (visited[i] == 2) cnt2++;
				else if (visited[i] == 3) cnt3++;
			}
			lint ans = 0;
			N -= cnt1;
			for (int i = 0; i < M; i++) if (visited[i] == 1) ans += i;
			lint loop_sum = 0;
			for (int i = 0; i < M; i++) if (visited[i] == 2 || visited[i] == 3) loop_sum += i;
			ans += (lint)loop_sum * (N / (cnt3 + cnt2));
			for (int i = 0; i < N % (cnt3 + cnt2); i++) {
				ans += now;
				now = beki[now];
			}
			cout << ans << endl;
			return 0;
		}
		else {
			now = beki[now];
		}
	}

	
	return 0;
}