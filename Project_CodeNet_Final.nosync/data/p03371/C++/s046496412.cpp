#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
#include <tuple>
#include <numeric>
#include <assert.h>
#include <functional>
#include <unordered_map>

using namespace std;

/*-----------------------------------------------------------------------------
　定義
 -------------------------------------------------------------------------------*/
#define ALL(a)			a.begin(), a.end()
#define REP(i, n)		for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n)	for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define INF				2e9
#define MOD				(1000 * 1000 * 1000 + 7)
#define Ceil(x, n)		(((((x))+((n)-1))/n))		/* Nの倍数に切り上げ割り算 */
#define CeilN(x, n)		(((((x))+((n)-1))/n)*n)		/* Nの倍数に切り上げ */
#define FloorN(x, n)	((x)-(x)%(n))				/* Nの倍数に切り下げ */
#define IsOdd(x)		(((x)&0x01UL) == 0x01UL)			
#define IsEven(x)		(!IsOdd((x)))						
#define	MAX_QWORD		((QWORD)0xFFFFFFFFFFFFFFFF)
#define M_PI			3.14159265358979323846
typedef long long		ll;
typedef pair<ll, ll>	P;

/*-----------------------------------------------------------------------------
　処理
 -------------------------------------------------------------------------------*/
int main()
{
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	
	ll ans = 0;
	ll cNum = min(X, Y);
	if (A + B < 2 * C) {
		ans = cNum * (A + B);
	} else {
		ans = cNum * C * 2;
	}

	X -= cNum;
	Y -= cNum;
	if (0 < X) {
		ans += min(X * A, X * C * 2);
	}
	if (0 < Y) {
		ans += min(Y * B, Y * C * 2);
	}
	cout << ans << endl;
	return 0;
}

