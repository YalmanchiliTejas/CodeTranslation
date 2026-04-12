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
//	freopen ("testcase.Rank_Checker", "r", stdin );

	int n, m;	// n: 整理番号 m: 正解数
	vector<P> rank; rank.clear();
	while (scanf ("%d,%d", &n, &m ), n|m ){
		rank.push_back (P (-m, n ) );
	} // end while
	sort (ALL (rank ) );
	vector<int> res (rank.size(), 0 );
	res[0] = 1;
	for (int i = 1; i < rank.size(); i++ ){
		if (rank[i].first == rank[i-1].first ){
			res[i] = res[i-1];
		}else{
			res[i] = res[i-1] + 1;
		} // end if
	} // end for
	int q;
	while (scanf ("%d", &q ) != EOF ){
		rep (i, rank.size() ){
			if (rank[i].second == q ){
				printf ("%d\n", res[i] );
				break;
			} // end if
		} // end rep
	} // end while

	return 0;
}