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

int S3[1024];

int main()
{
	rep (S, 1024 ){
		int stat = 0;
		rep (j, 10 ) if (S & (1<<j) ) {
			stat ^= 1<<j;
			if (j > 0 ) stat ^= 1<<(j-1);
			if (j < 9 ) stat ^= 1<<(j+1);
		} // end rep
		S3[S] = stat;
	} // end rep
	int T; scanf ("%d", &T );
	while (T--){
		int org[10] = {};
		rep (i, 10 ) rep (j, 10 ){
			int tmp; scanf ("%d", &tmp );
			org[i] |= tmp<<j;
		} // end rep
		
		int ans = -1;
		rep (S, 1024 ){
			int grid[10];
			rep (i, 10 ) grid[i] = org[i];
		
			grid[0] ^= S3[S];
			grid[1] ^= S;
			for (int i = 1; i < 10; i++ ){
				int pttn = grid[i-1];
				grid[i-1] = 0;
				grid[i] ^= S3[pttn];
				if (i < 9 ) grid[i+1]^=pttn;
			} // end if
			if (grid[9] == 0 ){
				ans = S; break;
			} // end if
		} // end rep
		if (ans == -1 ) while (1 );
	
		rep (j, 10 ) printf ("%d%c", !!(ans&(1<<j)), j<9 ? ' ' :'\n' );
		org[0] ^= S3[ans];
		org[1] ^= ans;
		for (int i = 1; i < 10; i++ ){
			int pttn = org[i-1];
			org[i-1] = 0;
			org[i] ^= S3[pttn];
			if (i < 10 ) org[i+1]^=pttn;
			rep (j, 10 ) printf ("%d%c", !!(pttn&(1<<j)), j<9 ? ' ' : '\n' ); 
		} // end for
	} // end while

	return 0;
}