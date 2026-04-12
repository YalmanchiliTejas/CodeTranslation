#define _USE_NATH_DEFINES
#include<cstdio>
#include <iostream>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<complex>
#include <string>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<numeric>
#include<limits>
#include<climits>
#include<cfloat>
#include<functional>
#include<iterator>
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
using namespace std;

#define INF 100000000


int main() {
	int n, k;
	string s;
	cin >> n >> s >> k;
	char t = s[k-1];
	rep(i, n) {
		if (s[i] != t) {
			s[i] = '*';
		}
	}
	cout << s << endl;
	return 0;
}