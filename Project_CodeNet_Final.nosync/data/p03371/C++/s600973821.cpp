#define _USE_NATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
#include <random>
#include <tuple>


using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
#define EPS 1e-9
const int INF = 1050000000;
const long long LINF = 1LL << 60;
const ll MOD = 1e9 + 7;
const int MINF = -1050000000;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	
	int s[4];
	s[0] = max(x, y) * 2 * c;
	s[1] = 2 * x * c + max(0, y - x) * b;
	s[2] = 2 * y * c + max(0, x - y) * a;
	s[3] = x * a + y * b;
	int sum = INF;
	rep(i, 4) sum = min(sum, s[i]);
	cout << sum << endl;
	return 0;
}
