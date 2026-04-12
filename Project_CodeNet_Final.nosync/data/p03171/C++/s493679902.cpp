//coded by not_surrender

#pragma GCC optimize( "Ofast" )

#include <bits/stdc++.h>

#define MAXN 3010
#define oo (1<<30)
#define MOD 1000000007
#define mid ((a+b)/2)
#define L (nod*2)
#define R (nod*2+1)
#define pb push_back

using namespace std;

typedef long long ll;
typedef vector <int> vi;

ll N, A[MAXN], dp[MAXN][MAXN][2];

bool mk[MAXN][MAXN];

void solve( int a, int b, int turn ){
	mk[a][b] = true;
	if ( a == b ){
		dp[a][b][turn] += A[a];
		return;
	}	
	if ( !mk[a+1][b] )
		solve( a+1, b, turn^1 );
	if ( !mk[a][b-1] )
		solve( a, b-1, turn^1 );
	if ( turn ){
		if ( (dp[a+1][b][turn]+A[a])-dp[a+1][b][turn^1] > (dp[a][b-1][turn]+A[b])-dp[a][b-1][turn^1] )
			dp[a][b][turn] = dp[a+1][b][turn]+A[a], dp[a][b][turn^1] = dp[a+1][b][turn^1];
		else
			dp[a][b][turn] = dp[a][b-1][turn]+A[b], dp[a][b][turn^1] = dp[a][b-1][turn^1];	
	}
	else {
		if ( dp[a+1][b][turn^1]-(dp[a+1][b][turn]+A[a]) < dp[a][b-1][turn^1]-(dp[a][b-1][turn]+A[b]) )
			dp[a][b][turn] = dp[a+1][b][turn]+A[a], dp[a][b][turn^1] = dp[a+1][b][turn^1];
		else
			dp[a][b][turn] = dp[a][b-1][turn]+A[b], dp[a][b][turn^1] = dp[a][b-1][turn^1];	
	}
}

int main(){

    #ifndef ONLINE_JUDGE
        //~ freopen( "a.txt", "r", stdin );
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio( false );
    cin.tie( NULL ), cout.tie( NULL );
    
    cin >> N;
    
    for ( int i = 1; i <= N; ++i )
		cin >> A[i];
	
	solve( 1, N, 0 );
	
	cout << dp[1][N][0]-dp[1][N][1] << '\n';
	
return 0;
}
