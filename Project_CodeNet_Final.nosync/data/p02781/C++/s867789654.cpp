#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	int K;
	cin >> S >> K;

	int N = S.size();
	vector<vector<vector<int>>> dp( N + 1, vector<vector<int>>( 2, vector<int>( K + 2 ) ) );
	dp[0][0][0] = 1;
	for( int i = 0; i < N; i++ ) {
		for( int j = 0; j < 2; j++ ) {
			int lim = S[i] - '0';
			if( j ) lim = 9;
			for( int k = 0; k <= K; k++ ) {
				for( int x = 0; x <= lim; x++ ) {
					int kk = 0;
					if( x ) kk = 1;
					dp[i + 1][j || x < lim][k + kk] += dp[i][j][k];
				}
			}
		}
	}

	int ans = dp[N][0][K] + dp[N][1][K];

	cout << ans << endl;
}
