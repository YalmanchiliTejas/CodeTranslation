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
const int MAXN = 100007;

struct eT
{
	void setd ( int _u, int _v, int _l )
	{
		u = _u, v = _v, last = _l;
	}
	
	int u, v, last;
}edge[MAXN*2];

int n;
int ke, la[MAXN];
int deg[MAXN];
bool dp[MAXN];
bool isl[MAXN];
int lev[MAXN], fa[MAXN];
AR(int) ar[MAXN];

void init ();
void input ();
void work ();

void dfs ( int now, int nf, int nl )
{
	lev[now] = nl;
	fa[now] = nf;
	for ( int i = la[now]; ~i; i = edge[i].last ) if ( edge[i].v ^ nf ) dfs ( edge[i].v, now, nl+1 );
}



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
	
	scanf ( "%d", &n );
	int u, v;
	INIT ( la, -1 );
	lp ( i, 1, n ){
		scanf ( "%d%d", &u, &v );
		edge[ke].setd ( u, v, la[u] );
		la[u] = ke++;
		edge[ke].setd ( v, u, la[v] );
		la[v] = ke++;
		++deg[u], ++deg[v];
	}
}

void work ()
{
	// main work
	
	if ( n == 2 ){
		cout << "Second" << endl;
		return;
	}
	
	lpi ( i, 1, n ) if ( la[edge[i].v] == -1 ) isl[i] = true;
	
	lpi ( i, 1, n ){
		if ( deg[i] > 1 ){
			dfs ( i, -1, 1 );
			break;
		}
	}
	
	lpi ( i, 1, n ) ar[lev[i]].PB ( i );
	
	int c0, c1;
	lpd ( i, n, 0 ){
		for ( auto x : ar[i] ){
//			cerr << x << endl;
			if ( !isl[x] ){
				c0 = c1 = 0;
				for ( int j = la[x]; ~j; j = edge[j].last ){
					if ( edge[j].v ^ fa[x] ){
						if ( dp[edge[j].v] ) ++c1;
						else ++c0;
					}
				}
				if ( c0 > 1 ){
					cout << "First" << endl;
					return;
				}
				dp[x] = c0 ? true : false;
			}
		}
	}
	
	cout << ( dp[ar[1][0]] ? "Second" : "First" ) << endl;
}