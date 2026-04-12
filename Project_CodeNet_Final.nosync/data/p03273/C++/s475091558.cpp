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

bool a[200], b[200];

int main() {
	int n, m;
	cin >> n >> m;
	string s[110];
	rep(i, n) {
		cin >> s[i];
		rep(j, m) {
			a[i] = a[i] || (s[i][j] == '#');
			b[j] = b[j] || (s[i][j] == '#');
		}
	}
	rep(i, n) {
		rep(j, m) {
			if (a[i] && b[j])cout << s[i][j];
		}
		if (a[i])cout << endl;
	}
	return 0;
}