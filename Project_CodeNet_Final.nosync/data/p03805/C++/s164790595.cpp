#include <bits/stdc++.h>
using namespace std;

#define MAX 8

int N, M;
bool A[MAX][MAX];

int memo[MAX][MAX + 1][(1 << MAX) + 1];

int dfs( int n, int cnt, int visit )
{
	if( cnt >= N ) {
		return 1;
	}
	if( memo[n][cnt][visit] ) {
		return memo[n][cnt][visit];
	}
	int res = 0;
	visit |= 1 << n;
	for( int i = 0; i < N; i++ ) {
		if( A[n][i] && ((1 << i) & visit) == 0 ) {
			res += dfs( i, cnt + 1, visit );
		}
	}
	memo[n][cnt][visit] = res;
	return res;
}

int main() {
	cin >> N >> M;
	for( int i = 0; i < M; i++ ) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		A[a][b] = true;
		A[b][a] = true;
	}

	int ans = dfs( 0, 1, 0 );

	cout << ans << endl;

	return 0;
}
