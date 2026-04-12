#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3005;

ll dp[MAXN][MAXN], S[MAXN];

int A[MAXN];

int N;

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> A[i];
		S[i] = S[i-1] + A[i];
		dp[i][i] = A[i];
	}

	for(int l = 2; l <= N; l++)
		for(int s = 1, e = l; e <= N; s++, e++)
			dp[s][e] = (S[e]-S[s-1]) - min(dp[s+1][e], dp[s][e-1]);

	cout << dp[1][N]*2 - S[N] << endl;
	return 0;
}