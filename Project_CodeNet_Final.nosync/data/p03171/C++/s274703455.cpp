// youngjinp20
// 2020 03

#include <bits/stdc++.h>
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; }
#define byr(x) [](const auto& a, const auto& b) { return a.x > b.x; }
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
using namespace std;

typedef long long ll;

const int MAX = 3000;
int N;
ll a[MAX];
ll dp[MAX][MAX];

ll solve(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	if (l == r) return a[l];
	return dp[l][r] = max(a[l] - solve(l+1, r), a[r] - solve(l, r-1));
}

int main() {
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> a[i];
	}
	for (int i=0; i<MAX; i++) {
		for (int j=0; j<MAX; j++) {
			dp[i][j] = -1;
		}
	}
	cout << solve(0, N-1) << endl;

	return 0;
}
