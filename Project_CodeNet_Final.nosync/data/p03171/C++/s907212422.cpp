#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3002;

ll dp[MAXN][MAXN][2];
bool vis[MAXN][MAXN];
int A[MAXN], N;

// ll solve(int i, int j, int p, int diff) {

// 	if (j == i)
// 	{	if (p == 1)
// 			return diff + A[i];
// 		else return diff - A[i];
// 	}
// 	//if (j < i) return diff;
// 	if (dp[i][j][p][diff] != -1)return dp[i][j][p][diff];
// 	int X = 0, Y = 0;
// 	if (p == 1)
// 	{
// 		X = solve(i, j - 1, p ^ 1, diff + A[j]);
// 		Y = solve(i + 1, j, p ^ 1, diff + A[i]);
// 	} else {
// 		X = solve(i, j - 1, p ^ 1, diff - A[j]);
// 		Y = solve(i + 1, j, p ^ 1, diff - A[i]);
// 	}

// 	if (p == 1)
// 		dp[i][j][p][diff] = max(X, Y);
// 	else  dp[i][j][p][diff] = min(X, Y);

// 	if (p == 1)
// 		return max(X, Y);
// 	else return min(X, Y);
// }
ll solve(int i, int j, int p) {

	if (j == i)
	{	if (p == 1)
			return A[i];
		else return  - A[i];
	}
	//if (j < i) return diff;
	if (dp[i][j][p]  != -1)return dp[i][j][p] ;

	if (p == 1)
	{
		dp[i][j][p] = max( A[j] + solve(i, j - 1, p ^ 1), A[i] + solve(i + 1, j, p ^ 1));

	} else {
		dp[i][j][p] = min(-A[j] + solve(i, j - 1, p ^ 1), -A[i] + solve(i + 1, j, p ^ 1));
	}

	// if (p == 1)
	// 	dp[i][j][p][diff] = max(X, Y);
	// else  dp[i][j][p][diff] = min(X, Y);

	// if (p == 1)
	// 	return max(X, Y);
	// else return min(X, Y);
	return dp[i][j][p];
}
int main() {

	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	cout << solve(1, N, 1);
	//cout << abs(X - Y) << endl;

	return 0;

}