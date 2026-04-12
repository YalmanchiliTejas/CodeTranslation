#include "bits/stdc++.h"
using namespace std;

struct dat {
	int x, y, z;
};

int main() {
	int N;
	cin >> N;
	vector<int>A(3 * N + 2);
	for (int i = 0; i < 3 * N; ++i) {
		int n;
		cin >> n;
		n--;
		A[i] = n;
	}
	A[3 * N] = N;
	A[3 * N + 1] = N;
	vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1e9));
	vector<int> dp2(N + 1, -1e9);
	dp[A[0]][A[1]] = 0;
	dp[A[1]][A[0]] = 0;
	dp2[A[0]] = 0;
	dp2[A[1]] = 0;

	int add = 0;
	int premax = 0;

	for (int i = 0; i < 3 * N; i += 3) {
		vector<dat>upd;
		vector<int>B{ A[i + 2],A[i + 3],A[i + 4] };
		sort(B.begin(), B.end());
		if (B[0] == B[2]) {//aaa
			add++;
			continue;
		}
		if (B[0] == B[1]) {//aab
			for (int j = 0; j < N; ++j) {
				upd.push_back({ j,B[2] , dp[B[0]][j] + 1 });
			}
			upd.push_back({ B[0],B[1] , dp[B[2]][B[2]] + 1 });
		}
		else if (B[1] == B[2]) {//abb
			for (int j = 0; j < N; ++j) {
				upd.push_back({ j,B[0] , dp[B[1]][j] + 1 });
			}
			upd.push_back({ B[1],B[2] , dp[B[0]][B[0]] + 1 });
		}
		else {
			//abc
			upd.push_back({ B[1],B[2] , dp[B[0]][B[0]] + 1 });
			upd.push_back({ B[0],B[2] , dp[B[1]][B[1]] + 1 });
			upd.push_back({ B[0],B[1] , dp[B[2]][B[2]] + 1 });
		}
		for (int j = 0; j < N; ++j) {
			upd.push_back({ j, B[0], dp2[j] });
			upd.push_back({ j, B[1], dp2[j] });
			upd.push_back({ j, B[2], dp2[j] });
		}
		upd.push_back({ B[0],B[1] , premax });
		upd.push_back({ B[0],B[2] , premax });
		upd.push_back({ B[1],B[2] , premax });
		for (int i = 0; i < upd.size(); ++i) {
			int x = upd[i].x;
			int y = upd[i].y;
			int z = upd[i].z;
			dp[x][y] = max(dp[x][y], z);
			dp[y][x] = max(dp[y][x], z);
			premax = max(premax, z);
			dp2[x] = max(dp2[x], z);
			dp2[y] = max(dp2[y], z);
		}
	}
	cout << premax + add << endl;
	return 0;
}
