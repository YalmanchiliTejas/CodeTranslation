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
#include <functional>

using namespace std;
#define ALL(x)              (x).begin(),(x).end()
#define REP(i, n)           for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n)       for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define INF                 (ll)2e9
#define MOD                 (1000 * 1000 * 1000 + 7)
#define Ceil(x, n)          (((((x))+((n)-1))/n))
#define CeilN(x, n)         (((((x))+((n)-1))/n)*n)
#define FloorN(x, n)        ((x)-(x)%(n))
#define IsOdd(x)            (((x)&0x01UL) == 0x01UL)
#define IsEven(x)           (!IsOdd((x)))
#define M_PI                3.14159265358979323846
typedef long long           ll;
typedef pair<ll, ll>	    P;

/*-----------------------------------------------------------------------------
　処理
 -----------------------------------------------------------------------------*/
// メイン
int main()
{
	int N;
	cin >> N;
	vector<int> A(N);
	REP(i, N) cin >> A[i];

	multiset<int> val;
	val.insert(A[0]);
	REPN(i, 1, N) {
		auto it = val.lower_bound(A[i]);
		if (it == val.begin()) {
			val.insert(A[i]);
		} else {
			val.erase(--it);
			val.insert(A[i]);
		}
	}

	cout << val.size() << endl;
	return 0;
}
