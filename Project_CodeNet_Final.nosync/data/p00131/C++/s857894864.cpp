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

const int dx[5] = { -1, 0, 0, 0, 1 };
const int dy[5] = {  0,-1, 0, 1, 0 };
int stage[10][10];
int cnt[10][10];

int Color(int y, int x ){
	int tmp = stage[y][x];
	rep (i, 5 ){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 10 || ny >= 10 || nx < 0 || ny < 0 ) continue;
		tmp += cnt[ny][nx];
	} // end rep

	return tmp%2;
}

int solve(){
	for (int y = 1; y < 10; y++)
		rep (x, 10 )
			if (Color(y-1, x ) ) cnt[y][x]=1;
	rep (i, 10 )
			if (Color(9, i ) ) return -1;

	int ret=0;
	rep (y, 10 ) rep (x, 10 ) ret+=cnt[y][x];

	return ret;
}

int ans[10][10];

void bit_dfs(){

	int res = -1;
	rep (i, 1<<10 ){
		memset (cnt, 0, sizeof (cnt ) );
		rep (j, 10 ) cnt[0][j]=(i>>j)&1;
		int t = solve();
		if (t >= 0 && (res < 0 || res > t ) ){
			res = t;
			memcpy (ans, cnt, sizeof(cnt ) );
		} // end if
	} // end rep
}

int main()
{
	int T; scanf("%d", &T );
	while (T--){
		memset (ans, 0, sizeof(ans ) );
		memset (cnt, 0, sizeof(cnt ) );
		memset (stage, 0, sizeof(stage ) );
		rep (y, 10 ) rep (x, 10 ) cin >> stage[y][x];
		bit_dfs();
		rep (y, 10 ) rep (x, 10 ) cout << ans[y][x] << (x < 9 ? ' ' : '\n' );
	} // end while
	return 0;
}