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
#include <cstdio>	// require printf, atoi
#include <functional>
#include <numeric>	// require accumulate
#include <cmath>		// require sqrt ceil floor
#include <climits>	// require INT_MAX etc
#include <limits>
#include <cfloat>
#include <iomanip>	// require setw
#include <sstream>	// require stringstream 
#include <cstring>	// require memset
#include <cctype>	// require tolower, toupper
#include <stdint.h>	// require uint64_t
#include <fstream>	// require freopen

using namespace std;

bool check (string w, int n )
{
	if (n % 15 == 0 ){
		return (w == "FizzBuzz" );
	} // end if

	if (n % 3 == 0 ){
		return (w == "Fizz" );
	} // end if

	if (n % 5 == 0 ){
		return (w == "Buzz" );
	} // end if
	
	for (int i = 0; i < w.length(); ++i ){
		if (w[i] < '0' || w[i] > '9' ){
			return false;
		} // end if
	} // end for

	return (atoi(w.c_str() ) == n );
}


int main()
{
//	cut here before submit 
//	freopen ("testcase.fizzbuzz", "r", stdin );
	int m, n;

	while (cin >> m >> n && m && n ){
		vector <int> player (m, 1 );
		vector <string> word (n+1 );
		for (int i = 1; i <= n; ++i ){
			cin >> word[i];
		} // end for
		int j = 0;
		for (int i = 1; i <= n; ++i ){
			if (check (word[i], i ) ){
				j = (j + 1 ) % m;
				while (!player[j] ){
					j = (j + 1) % m;
				} // end while
			}else{
				player[j] = 0;
				if ((int)count (player.begin(), player.end(), 1 ) < 2 ){
					break;
				} // end if
				while (!player[j] ) {
					j = (j + 1) % m;
				} // end while
			} // end if
		} // end for

		vector <int> res;
		res.clear();

		for (int i = 0; i < m; ++i ){
			if (player[i] ){
				res.push_back (i+1);
			} // end if
		} // end for

		for (int i = 0; i < res.size(); ++i ){
			cout << res[i];
			if (i != res.size() - 1 ){
				cout << ' ';
			} // end if
		} // end for
		cout << endl;
	} // end loop
		
	return 0;
}