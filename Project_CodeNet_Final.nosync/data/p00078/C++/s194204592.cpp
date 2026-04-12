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

int main()
{
//	cut here before submit 
//	freopen ("testcase.Magic_Square", "r", stdin );
	int n;
	while (scanf ("%d", &n ), n ){
		vector<vector<int> > board (n, vector<int> (n, 0 ) );
		int num = 1;
		int row = n/2+1;
		int col = n/2;
		board[row][col] = num++;
		while (num <= n*n ){
			row = (row + 1 ) % n;
			col = (col + 1 ) % n;
			if (board[row][col] == 0 ){
				board[row][col] = num++;
			}else{
				do{
					row = (row + 1 ) % n;
					col = (n + col - 1 ) % n;
				}while (board[row][col] != 0 );
				board[row][col] = num++;
			} // end if
		} // end while
		rep (i, n ){
			rep (j, n ){
				printf ("%4d", board[i][j] );
			} // end rep
			printf ("\n" );
		} // end rep
	} // end loop
		
	return 0;
}