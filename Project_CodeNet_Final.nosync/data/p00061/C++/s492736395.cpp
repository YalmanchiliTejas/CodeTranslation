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
//	freopen("testcase.rank", "r", stdin);
	string str = "";
	multimap <int, int, greater<int> > result;
	while (getline (cin, str ) ){
		int team, score;
		while (str.find(',') != string::npos ){
			str = str.replace(str.find(','), 1, " ");
		} // end while
		stringstream ss(str);
		ss >> team >> score;
		if (team == 0 && score == 0){
			break;
		} // end if
		result.insert (make_pair (score, team ) );
	} // end while

	while (getline (cin, str ) ){
		int team;
		if (str.empty() ){
			break;
		} // end if	
		stringstream ss (str );
		ss >> team;
		int rank = 0;
		int score = 0;
		int pre = -1;
		int res = 0;
		multimap <int, int, greater<int> >::iterator it = result.begin();
		for (; it != result.end(); ++it){
			score = (*it).first;
			if (score != pre ){
				++rank;
			} // end if
			if ((*it).second == team ){
				res = rank;
				break;
			} // end if
			pre = score;
		} // end for
		cout << res << endl;
	} // end loop
		
	return 0;
}