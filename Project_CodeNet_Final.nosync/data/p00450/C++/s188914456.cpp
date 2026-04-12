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
typedef pair<bool, int> BI;

bool stone[100005];

int main()
{
//	cut here before submit 
//	freopen ("testcase.SGS", "r", stdin );
	int n;
	while (scanf ("%d", &n ), n ){
		memset (stone, false, sizeof (stone ) );
		rep (i, n ){
			int in;
			scanf ("%d", &in );
			stone[i] = (in == 1 ? true : false );
		} // end rep
		stack<BI> st;
		st.push (BI (stone[0], 1 ) );
		for (int i = 1; i < n; i++ ){
			// 前の碁石と色が同じとき
			if (st.top().first == stone[i] ){
				st.top().second++;
			}else
			if ((i+1) % 2 == 0 ){		// 偶数番目のとき
				int curr = 0;
				do{
					curr += st.top().second; st.pop();
				}while (!st.empty() && st.top().first != stone[i] );
				st.push (BI (stone[i], curr + 1 ) );
			}else{						// 奇数番目のとき
				st.push (BI (stone[i], 1 ) );	
			} // end if
		} // end for

		int res = 0;
		while (!st.empty() ){
			BI curr = st.top(); st.pop();
			if (!curr.first ) res += curr.second;
		} // end while
		printf ("%d\n", res ); 
	} // end loop
		
	return 0;
}