#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
static const double PI2 = 8.0 * atan(1.0);

#define REP(i,n)	for(int i=0;i<(int)n;++i)
#define ALL(c)		(c).begin(),(c).end()
#define CLEAR(v)	memset(v,0,sizeof(v))
#define MP(a,b)		make_pair((a),(b))
#define ABS(a)		((a)>0?(a):-(a))
#define FOR(i,s,n)	for(int i=s;i<(int)n;++i)

int H, W;
char A[8][8];

int main(int argc, char **argv) {
	cin >> H >> W;
	REP(y, H) REP(x, W) cin >> A[x][y];
	int x = 0, y = 0;
	while (x != W - 1 || y != H - 1) {
		A[x][y] = '.';
		if (x < W - 1 && A[x + 1][y] == '#') {
			++x;
		}
		else if (y < H - 1 && A[x][y + 1] == '#') {
			++y;
		}
		else {
			break;
		}
	}
	A[x][y] = '.';
	bool res = true;
	REP(x, W) REP(y, H) if (A[x][y] == '#') res = false;
	cout << (res ? "Possible" : "Impossible") << endl;
	return 0;
}
