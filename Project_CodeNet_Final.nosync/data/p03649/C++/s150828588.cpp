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
const int MAXN = 53;

int n;
LL a[MAXN];
LL nd[MAXN];

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

	cin >> n;
	lpi ( i, 1, n ) cin >> a[i];
}

void work ()
{
	// main work

	LL k = 0;
	LL nc = 0;
	bool flag;
	while ( 1 ){
		flag = true;
		lpi ( i, 1, n ) if ( a[i] >= n ) { flag = false; break; }

		if ( flag ) break;

		nc = 0;
		lpi ( i, 1, n ){
			nd[i] = a[i] / n;
			a[i] %= n;
			nc += nd[i];
			k += nd[i];
		}

		lpi ( i, 1, n ) a[i] += nc - nd[i];
	}

	cout << k << endl;
}