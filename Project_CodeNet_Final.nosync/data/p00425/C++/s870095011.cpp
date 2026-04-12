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

const int init[] = { 1, 2, 3, 4, 5, 6 };
const int move[][4] = {
							{ 0, 1, 5, 4 }, 	// north
							{ 0, 3, 5, 2 }, 	// east
							{ 0, 2, 5, 3 },	// west
							{ 0, 4, 5, 1 },	// south
							{ 4, 3, 1, 2 },	// right
							{ 4, 2, 1, 3 }		// left
						};
const string words[] = { "North", "East", "West", "South", "Right", "Left" };
int d[6];

void moving (int m )
{
	int temp = d[move[m][0]];
	rep (i, 3 ){
		d[move[m][i]] = d[move[m][i+1]];
	} // end rep
	d[move[m][3]] = temp;
} 

int main()
{
//	cut here before submit 
//	freopen ("testcase.dice", "r", stdin );
	int n;
	while (scanf ("%d", &n ), n ){
		memset (d, 0, sizeof (d ) );
		rep (i, 6 ) d[i] = init[i];
		int res = d[0];
		rep (i, n ){
			string w = "";
			cin >> w;
			int turn = -1;
			rep (j, 6 ){
				if (w == words[j] ){
					turn = j;
					break;
				} // end if
			} // end rep
			moving (turn );
			res += d[0];
		} // end rep
		printf ("%d\n", res );
	} // end loop
	
	return 0;
}