#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using mii = map<int, int>;
using msi = map<string, int>;
using pii = pair<int, int>;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    int n;
    cin >> n;

	const int L = S.size();

    long long dp[ 1200 ][ 2 ][ 4 ];   // 未満, 含むか

	fill( ( long long * )dp, ( long long * )dp + sizeof( dp ) / sizeof( long long ), 0 );
	dp[0][0][0] = 1;

	for ( int i = 0; i < L; ++i )
	{
		const int D = S[i] - '0';
		for ( int j = 0; j < 2; ++j )
		{
			for ( int k = 0; k <= n; ++k )
			{
				for ( int d = 0; d <= ( k == n ? 0 : (j ? 9 : D )); ++d )
				{
					dp[ i + 1 ][ j || ( d < D ) ][ d == 0 ? k : k + 1] += dp[i][j][k];
				}
			}
		}
	}

    ll ans = 0;

	cout << dp[L][0][n] + dp[L][1][n] << endl;

    return 0;
}