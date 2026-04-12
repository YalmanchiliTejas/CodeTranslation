#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast<t>(x)
#define AR(t) vector < t >
#define PII pair < int, int >
#define PLL pair < LL, LL >
#define PIL pair < int, LL >
#define PLI pair < LL, int >
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define PRF first
#define PRS second
#define INIT(ar,val) memset ( ar, val, sizeof ( ar ) )
#define lp(loop,start,end) for ( int loop = start; loop < end; ++loop )
#define lpd(loop,start,end) for ( int loop = start; loop > end; --loop )
#define lpi(loop,start,end) for ( int loop = start; loop <= end; ++loop )
#define lpdi(loop,start,end) for ( int loop = start; loop >= end; --loop )
#define qmax(a,b) (((a)>(b))?(a):(b))
#define qmin(a,b) (((a)<(b))?(a):(b))
#define qabs(a) (((a)>=0)?(a):(-(a)))

const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 11;

int n, m;
char s[MAXN][MAXN];
bool okr[MAXN][MAXN], okc[MAXN][MAXN], dp[MAXN][MAXN];

void init ();
void input ();
void work ();



int main()
{
	init();
	input();
	work();
}



void init ()
{
	// Init Everything Here
	
	ios::sync_with_stdio ( false );
}

void input ()
{
	// input method
	
	scanf ( "%d%d", &n, &m );
	lpi ( i, 1, n ) scanf ( "%s", s[i]+1 );
}

void work ()
{
	// main work
	
	lpi ( i, 1, n ) okr[i][0] = true;
	lpi ( i, 1, m ) okc[0][i] = true;
	lpi ( i, 1, n ) lpi ( j, 1, m ) okr[i][j] = okr[i][j-1] & ( s[i][j] == '.' ), okc[i][j] = okc[i-1][j] & ( s[i][j] == '.' );
	
	dp[1][1] = true;
	lpi ( i, 1, n ){
		lpi ( j, 1, m ){
			if ( dp[i][j] ){
				if ( i < n && okr[i+1][j-1] ) dp[i+1][j] = true;
				if ( j < m && okc[i-1][j+1] ) dp[i][j+1] = true;
			}
		}
	}
	
	cout << ( dp[n][m] ? "Possible\n" : "Impossible\n" ) << endl;
}