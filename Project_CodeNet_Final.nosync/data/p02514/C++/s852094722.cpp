#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>	// require sort next_permutation count etc.
#include <cstdlib>	// require abs
#include <cstdio>	// require printf
#include <functional>
#include <numeric>	// require accumulate
#include <cmath>
#include <climits>
#include <limits>
#include <cfloat>
#include <iomanip>	// require setw
#include <sstream>	// require stringstream 
#include <cstring>	// require memset
#include <cctype>	// require tolower, toupper
#include <fstream>	// require freopen

using namespace std;

typedef pair <int, pair<int, int> > D;

int main()
{
//	cut here before submit 
//	freopen ("testcase.darkprogrammer", "r", stdin );
	int n;

	while (cin >> n && n ){
		vector <D> date(n);

		for (int i = 0; i < n; ++i){
			int year, month, day;
			cin >> year >> month >> day;
			date[i].first = year;
			date[i].second.first = month;
			date[i].second.second = day;
		} // end for

		sort (date.begin(), date.end() );

		for (int i = 0; i < n; ++i ){
			printf ("%04d %02d %02d\n", date[i].first, date[i].second.first, date[i].second.second );
		} // end for
	} // end loop
	
	return 0;
}