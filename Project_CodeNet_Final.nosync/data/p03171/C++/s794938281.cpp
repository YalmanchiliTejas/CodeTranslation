#include <bits/stdc++.h>
using namespace std;
#define ll long long

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}
#define int long long
#define MAX 3001
int dp[MAX][MAX];
int play(vector<int> &game, int i, int j) {
	if (i > j) return 0;
	if (i == j)
		dp[i][j] = game[i];
	else if (dp[i][j] == -1) {
		// if the current player wants to win, he can win in 2 ways
		// take i
		int sum1 = 0;
		{
			// second player take i+1
			int a = game[i] + play(game, i + 2, j);
			// second player take j
			int b = game[i] + play(game, i + 1, j - 1);
			sum1 = min(a, b);
		}
		// take j
		int sum2 = 0;
		{
			// second player takes i
			int a = game[j] + play(game, i + 1, j - 1);
			// second player takes j - 1
			int b = game[j] + play(game, i, j - 2);
			sum2 = min(a, b);
		}
		dp[i][j] = max(sum1, sum2);
	}
	return dp[i][j];
}


#undef int
int main(int argc, char const *argv[])
{
	#define int long long
	int n;
	cin >> n;
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j)
			dp[i][j] = -1;
	vector<int> game(n);
	int total = 0;
	for(int i = 0; i < n; ++i) {
		cin >> game[i];
		total += game[i];
	}
	int X = play(game, 0, n - 1);
	int Y = total - X;
	cout << X - Y << endl;
	return 0;
}