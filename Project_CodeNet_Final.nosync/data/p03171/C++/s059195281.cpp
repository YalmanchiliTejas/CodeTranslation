#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

constexpr int MAXN = 3000;

ll dp[MAXN + 2][MAXN + 2];

int main() {
	int N;
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> dp[1][i];
	for(int i = 2; i <= N; i++)
		for(int j = 0; i + j <= N; j++)
			dp[i][j] = max(dp[1][i + j - 1] - dp[i - 1][j], dp[1][j] - dp[i - 1][j + 1]);
	cout << dp[N][0] << endl;
}
