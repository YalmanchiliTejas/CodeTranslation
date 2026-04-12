////////////////////////////////////////////////////////////////////
// This source code is for Visual Studio
////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <stack>
#include <functional>
#include <iomanip>
#include <string>
#include <cstring>
#include <deque>
#include <math.h>
#include <assert.h>

#define	numberof(a)	(sizeof(a) / sizeof(a[0]))
#define	INF		UINT64_MAX
#define Rep(i,n) for(int i = 0; i < (n); ++i )

using namespace std;

typedef vector< vector<int> > MAT;
typedef pair<int, int> PINT;
typedef long long ll;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int32_t s32;
typedef int64_t s64;

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

int main()
{
	ll A = 0;
	ll B = 0;
	ll C = 0;
	ll X = 0;
	ll Y = 0;
	ll ans = 0;

	cin >> A >> B >> C >> X >> Y;

	// solve
	if (A >= 2 * C && B >= 2 * C) {
		ans += max(X, Y) * 2 * C;
	}
	else if (A >= 2 * C) {
		ans += X * 2 * C;
		if(Y > X) ans += (Y - X) * B;
	}
	else if (B >= 2 * C) {
		ans += Y * 2 * C;
		if (X > Y) ans += (X - Y) * A;
	}
	else if (A + B >= 2 * C) {
		ans += min(X, Y) * 2 * C;
		if (X > Y) {
			ans += (X - Y) * A;
		}
		else {
			ans += (Y - X) * B;
		}
	}
	else {
		// buy each pizza
		ans += X * A;
		ans += Y * B;
	}

	cout << ans << endl;

	return 0;
}
