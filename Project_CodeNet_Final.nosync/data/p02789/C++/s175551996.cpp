#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
#include <numeric>

using namespace std;

/*-----------------------------------------------------------------------------
　定義
 -------------------------------------------------------------------------------*/
#define ALL(x)				(x).begin(),(x).end()
#define REP(i, n)			for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n)		for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define INF					(ll)1e9
#define EPS					(double)1e-9
#define MOD					(1000 * 1000 * 1000 + 7)
#define Ceil(x, n)			(((((x))+((n)-1))/(n)))		/* Nの倍数に切り上げ割り算 */
#define CeilN(x, n)			(((((x))+((n)-1))/(n))*(n))	/* Nの倍数に切り上げ */
#define FloorN(x, n)		((x)-(x)%(n))				/* Nの倍数に切り下げ */
#define IsOdd(x)			(((x)&0x01UL) == 0x01UL)			
#define IsEven(x)			(!IsOdd((x)))						
#define M_PI				3.14159265358979323846
typedef long long			ll;
typedef pair<ll, ll>		P;

/*-----------------------------------------------------------------------------
　処理
 -------------------------------------------------------------------------------*/
// メイン
int main()
{
	int N, M;
	cin >> N >> M;

	string ans;
	if (N == M) {
		ans = "Yes";
	} else {
		ans = "No";
	}
	cout << ans << endl;
	return 0;
}

