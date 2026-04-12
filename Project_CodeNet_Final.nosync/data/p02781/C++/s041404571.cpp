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
#define ALL(x)			(x).begin(),(x).end()
#define REP(i, n)		for (int (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n)	for (int (i) = m ; (i) < (ll)(n) ; ++(i))
#define INF				(int)2e9
#define MOD				(1000 * 1000 * 1000 + 7)
#define Ceil(x, n)		(((((x))+((n)-1))/n))		/* Nの倍数に切り上げ割り算 */
#define CeilN(x, n)		(((((x))+((n)-1))/n)*n)		/* Nの倍数に切り上げ */
#define FloorN(x, n)	((x)-(x)%(n))				/* Nの倍数に切り下げ */
#define IsOdd(x)		(((x)&0x01UL) == 0x01UL)			
#define IsEven(x)		(!IsOdd((x)))						
#define M_PI			3.14159265358979323846
typedef long long		ll;
typedef pair<ll, ll>	P;
typedef vector<ll>		VLL;
typedef vector<VLL>		VVLL;
typedef vector<VVLL>	VVVLL;

int main()
{
    string N;
    int K;
    cin >> N >> K;

	int ketaNum = N.size();
	VVLL dp0(ketaNum + 1, VLL(K + 1, 0));
	VVLL dp1(ketaNum + 1, VLL(K + 1, 0));
	
	dp0[0][0] = 1;
	REP(i, ketaNum) {
		int digitMax = N[i] - '0';
		REP(j, K + 1) {
			REP(digitVal, 10) {
				if (digitVal == 0) {
					if (digitVal < digitMax) {
						dp1[i + 1][j] += (dp0[i][j] + dp1[i][j]);
					} else if (digitVal == digitMax) {
						dp0[i + 1][j] += dp0[i][j];
						dp1[i + 1][j] += dp1[i][j];
					} else {
						dp1[i + 1][j] += dp1[i][j];
					}
				} else {
					if (j < K) {
						if (digitVal < digitMax) {
							dp1[i + 1][j + 1] += (dp0[i][j] + dp1[i][j]);
						} else if (digitVal == digitMax) {
							dp0[i + 1][j + 1] += dp0[i][j];
							dp1[i + 1][j + 1] += dp1[i][j];
						} else {
							dp1[i + 1][j + 1] += dp1[i][j];
						}
					}
				}
			}
		}
	}

    cout << dp0[ketaNum][K] + dp1[ketaNum][K] << endl;
    return 0;
}
