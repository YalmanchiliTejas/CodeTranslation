#include <bits/stdc++.h>
using namespace std;

#define INF (INT64_MAX)
#define MOD (1000000000+7)
#define MAX 3000

int N, K;
int a[MAX];

long long memo[MAX + 1][MAX + 1][2];

long long dfs( int h, int t, int turn )
{
	if( h > t ) {
		return 0;
	}
	if( memo[h][t][turn] != INF ) {
		return memo[h][t][turn];
	}
	int s = 1;
	if( turn ) {
		s = -1;
	}
	long long res1 = dfs( h + 1, t, 1 - turn ) + a[h] * s;
	long long res2 = dfs( h, t - 1, 1 - turn ) + a[t] * s;
	long long res;
	if( turn ) {
		res = min( res1, res2 );
	}
	else {
		res = max( res1, res2 );
	}
	return memo[h][t][turn] = res;

}

int main() {
	cin >> N;
	for( int i = 0; i < N; i++ ) {
		cin >> a[i];
	}

	for( int i = 0; i < MAX + 1; i++ ) {
		for( int j = 0; j < MAX + 1; j++ ) {
			for( int k = 0; k < 2; k++ ) {
				memo[i][j][k] = INF;
			}
		}
	}
	long long ans = dfs( 0, N - 1, 0 );

	cout << ans << endl;

	return 0;
}
