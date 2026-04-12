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
//	freopen("testcase.tokaichi", "r", stdin);
	string str = "";
	map <int, char, greater<int> > shop;

	int i = 0;
	while (getline (cin, str ) ){
		char name = 'A' + i;
		int s1, s2;
		stringstream ss(str);
		ss >> s1 >> s2;

		if (s1 == 0 && s2 == 0){
			break;
		} // end if
		shop.insert (make_pair (s1+s2, name ) );
		++i;
		if (i < 5) {
			continue;
		} // end if

		map<int, char, greater<int> >::iterator it = shop.begin();
		cout << (*it).second << ' ' << (*it).first << endl;

		i = 0;
		shop.clear();
	} // end while
		
	return 0;
}