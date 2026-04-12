#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <numeric>
#include <cmath>
#include <climits>
#include <limits>
#include <cfloat>
#include <fstream>
using namespace std;

int main()
{
//	cut here before submit 
//	freopen ("testcase.LMSS", "r", stdin );
	string str = "";
	int i, n;
	vector <multimap <int, string > > res;

	while (getline (cin, str ) ){
		stringstream ssn(str);
		ssn >> n;
		
		if (n == 0 ){
			break;
		} // end if

		multimap <int, string> rank;

		for (i = 0; i < n; ++i){
			string team;
			int win, lose, draw;
			getline (cin, str );
			stringstream ss(str);
			ss >> team >> win >> lose >> draw;
			int point = 3*win + draw;
			rank.insert (make_pair (-point, team ) );
		} // end for
		res.push_back (rank );		
	} // end loop
	int size = res.size();
	
	for (i = 0; i < size; ++i){
		multimap <int, string>::iterator it = res[i].begin();
		for (; it != res[i].end(); ++it ){
			int point = -(*it).first;
			string team = (*it).second;
			cout << team << ',' << point << endl;
		} // end for
		if (i != size - 1){
			cout << endl;
		} // end if
	} // end for
		
	return 0;
}