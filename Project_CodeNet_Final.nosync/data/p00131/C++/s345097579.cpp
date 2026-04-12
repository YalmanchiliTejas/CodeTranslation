#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>	// require sort next_permutation count __gcd reverse etc.
#include <cstdlib>	// require abs exit atof atoi 
#include <cstdio>		// require scanf printf
#include <functional>
#include <numeric>	// require accumulate
#include <cmath>		// require fabs
#include <climits>
#include <limits>
#include <cfloat>
#include <iomanip>	// require setw
#include <sstream>	// require stringstream 
#include <cstring>	// require memset
#include <cctype>		// require tolower, toupper
#include <fstream>	// require freopen
#include <ctime>		// require srand
#define rep(i,n) for(int i=0;i<(n);i++)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[5] = { 0, 1, 0, -1, 0 };
const int dy[5] = {-1, 0, 1,  0, 0 };

int in[10][10];
int cnt[10][10];
int ans[10][10];

int color(int y, int x )
{
	int tmp = in[y][x];
	rep (k, 5 ){
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10 ) continue;
		tmp += cnt[ny][nx];
	} // end rep
	
	return tmp%2;
}

int solve()
{
	for (int i = 1; i < 10; i++ ) rep (j, 10 ) if (color(i-1, j ) ) cnt[i][j] = 1;
	rep (i, 10 ) if (color(9, i ) ) return -1;
	
	int ret = 0;
	rep (i, 10 ) rep (j, 10 ) ret += cnt[i][j];

	return ret;	
}

void dfs ()
{
	int res = -1;
	rep (i, 1<<10 ){
		memset (cnt, 0, sizeof (cnt ) );
		rep (j, 10 ) cnt[0][j] = (i>>j) & 1;
		int t = solve();
		if (t >= 0 && (res < 0 || res > t ) ){
			res = t;
			memcpy (ans, cnt, sizeof (cnt ) );
		} // end if
	} // end rep
}

int main()
{
	int T; cin >> T;
	while (T--){
		memset (in, 0, sizeof (in ) );
		memset (ans, 0, sizeof (ans ) );
		rep (i, 10 ) rep (j, 10 ) cin >> in[i][j];
		dfs ();
		rep (i, 10 ) rep (j, 10 ) cout << ans[i][j] << ( j < 9 ? ' ' : '\n' );
	} // end while
		
	return 0;
}