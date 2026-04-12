#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
#include <tuple>
#include <numeric>

using namespace std;

/*-----------------------------------------------------------------------------
　定義
 -------------------------------------------------------------------------------*/
#define ALL(a)			(a).begin(),(a).end()
#define REP(i, n)		for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n)	for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define INF				(1000 * 1000 * 1000 * 2)
#define MOD				(1000 * 1000 * 1000 + 7)
#define Ceil(x, n)		(((((x))+((n)-1))/n))		/* Nの倍数に切り上げ割り算 */
#define CeilN(x, n)		(((((x))+((n)-1))/n)*n)		/* Nの倍数に切り上げ */
#define FloorN(x, n)	((x)-(x)%(n))				/* Nの倍数に切り下げ */
#define IsOdd(x)		(((x)&0x01UL) == 0x01UL)			
#define IsEven(x)		(!IsOdd((x)))						
#define M_PI			3.14159265358979323846
typedef long long		ll;
typedef pair<int, int>	P;

/*-----------------------------------------------------------------------------
　処理
 -------------------------------------------------------------------------------*/
// 枝定義
struct Edge
{
	int	from;
	int	to;
	Edge(){}
	Edge(int a, int b): from(a), to(b){}
};

// dfs
int N, M;
int ans = 0;
vector<vector<int>>	G;
vector<bool>		isUsed;
void dfs(int from, int to)
{
	// 到達してないところがないか
	bool isFin = true;
	for (int j = 0; j < N; j++) {
		if (!isUsed[j]) {
			isFin = false;
			break;
		}
	}
	if (isFin) {
		ans++;
		return;
	}

	for (auto nextTo : G[to]) {
		if (from != nextTo) {
			if (!isUsed[nextTo]) {
				isUsed[nextTo] = true;
				dfs(to, nextTo);
				isUsed[nextTo] = false;
			}
		}
	}
}

// メイン
int main()
{
	cin >> N >> M;
	vector<Edge>	edgeList;
	REP(i, M) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		edgeList.emplace_back(a, b);
	}
	G.resize(N);
	for (int j = 0; j < M; j++) {
		const auto &edgeOne = edgeList[j];
		G[edgeOne.from].emplace_back(edgeOne.to);
		G[edgeOne.to].emplace_back(edgeOne.from);
	}

	int startPos = 0;
	isUsed.clear();
	isUsed.resize(N, false);
	isUsed[startPos] = true;
	dfs(-1, startPos);

	cout << ans << endl;
	return 0;
}
