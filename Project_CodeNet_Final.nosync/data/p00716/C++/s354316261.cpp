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
	int m;
	scanf ("%d", &m );
	while (m-- ){
		int cash; scanf ("%d", &cash );
		int year; scanf ("%d", &year );
		int kind; scanf ("%d", &kind );
		int res = 0;
		rep (i, kind ){
			int ss; double rate; int fee; scanf ("%d %lf %d", &ss, &rate, &fee );
			int sum1 = cash, sum2 = 0;
			rep (j, year ){
				double tmp = (double)sum1*rate;
				if (ss == 0 ){	// 単利
					sum2 += (int)tmp;
					sum1 -= fee;
				}else{			// 複利
					sum1 += (int)tmp;
					sum1 -= fee;
				} // end if
			} // end rep
			if (res < sum1 + sum2 ){
				res = sum1 + sum2;
			} // end if
		} // end rep
		printf ("%d\n", res );		
	} // end loop
		
	return 0;
}