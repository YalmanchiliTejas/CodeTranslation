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

int main() {
	int n;
	int h[25];
	cin >> n;
	rep(i, n) cin >> h[i];
	int ans = 0;
	int target = h[0];
	for (int i = 0; i < n;++i) {
		if (target <= h[i]) {
			ans++;
			target = h[i];
		}
	}
	cout << ans << endl;
	return 0;
}