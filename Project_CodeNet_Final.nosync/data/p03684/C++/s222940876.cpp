//#include "pch.h"
//#include "stdafx.h"
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <string>
#include <cstring>
#include <functional>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>

using namespace std;

/*-----------------------------------------------------------------------------
　ライブラリ
 -------------------------------------------------------------------------------*/
#if 0
// 3次元
vector<vector<vector<SDWORD>>> XXX(AAA, vector<vector<SDWORD>>(BBBB, vector<SDWORD>(CCC, -1)));
#endif

#if 0
// 2分探索
auto position = lower_bound(getValue.begin(), getValue.end(), 0);	// 0以上の要素位置を探す
int idx_lower = distance(getValue.begin(), position);				// 0以上の要素インデックス
int eraseNum = MIN(idx_lower, delCnt);								// 要素位置が個数になる
#endif

#if 0
// プライオリティーキュー、優先度
auto pqCmp = [](P a, P b) { return a.second > b.second; };
std::priority_queue<int, std::vector<int>, decltype(pqCmp)> que;
#endif


/*-----------------------------------------------------------------------------
　定義
 -------------------------------------------------------------------------------*/
#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))

#define INF						2e9
#define MOD						(1000 * 1000 * 1000 + 7)
#define MIN(a, b)				((a) < (b) ? a : b)
#define MAX(a, b)				((a) > (b) ? a : b)
#define CeilN(x, n)				(((((DWORD)(x))+((n)-1))/n)*n)	/* Nの倍数に切り上げ */
#define FloorN(x, n)			((x)-(x)%(n))					/* Nの倍数に切り下げ */
#define IsOdd(x)				(((x)&0x01UL) == 0x01UL)			
#define IsEven(x)				(!IsOdd((x)))						

#define ArrayLength(x)			( sizeof( x ) / sizeof( x[ 0 ] ) )
#define	ArrayEnd(a)				(&(a)[ArrayLength(a)])			
#define	ArrayLast(a)			(&(a)[ArrayLength(a) - 1])		
#define MAX_DWORD				(0xFFFFFFFF)
#define	MAX_SDWORD				((SDWORD)0x7FFFFFFF)
#define	MIN_SDWORD				((SDWORD)0x80000000)
#define	MAX_QWORD				((QWORD)0xFFFFFFFFFFFFFFFF)
#define	MIN_QWORD				((QWORD)0x0000000000000000)
#define	MAX_SQWORD				((SQWORD)0x7FFFFFFFFFFFFFFF)
#define	MIN_SQWORD				((SQWORD)0x8000000000000000)
#define M_PI					3.14159265358979323846
#define deg_to_rad(deg)			(((deg)/360)*2*M_PI)
#define rad_to_deg(rad)			(((rad)/2/M_PI)*360)

#define	BitSetV(Val,Bit)		((Val) |= (Bit))			
#define	BitTstV(Val,Bit)		((Val) & (Bit))				
typedef short					SWORD;
typedef long					SDWORD;
typedef long long				SQWORD;
typedef unsigned short			WORD;
typedef unsigned long			DWORD;
typedef unsigned long long int	QWORD;
typedef pair<int, int> P;

/*-----------------------------------------------------------------------------
　パラメータ定義
 -------------------------------------------------------------------------------*/
#define N_MAX	(100000)
#define K_MAX	(10)
#define M_MAX	(1000)
#define H_MAX	(1000)
#define W_MAX	(1000)
/*-----------------------------------------------------------------------------
　処理
 -------------------------------------------------------------------------------*/
struct edge {
	edge(int a, int b) {
		to = a;
		cost = b;
	}
	int to;
	int cost;
};

struct queInfo {
	queInfo(int a, int b) {
		idx = a;
		cost = b;
	}
	int idx;
	int cost;
};

bool cmpZahyou(P &a, P &b)
{
	return a.second < b.second;
}

// メイン
int main()
{
	int N;
	static vector<edge> G[N_MAX];

	// 入力
	{
		cin >> N;
		vector<P> zahyouX;
		vector<P> zahyouY;
		REP(i, N) {
			int x, y;
			cin >> x >> y;
			zahyouX.push_back(make_pair(i, x));
			zahyouY.push_back(make_pair(i, y));
		}

		// X方向のリスト
		sort(zahyouX.begin(), zahyouX.end(), cmpZahyou);
		REP(i, N - 1) {
			int prevIdx = zahyouX[i].first;
			int nextIdx = zahyouX[i + 1].first;
			int kyori = zahyouX[i + 1].second - zahyouX[i].second;
			G[prevIdx].push_back(edge(nextIdx, kyori));
			G[nextIdx].push_back(edge(prevIdx, kyori));
		}

		// Y方向のリスト
		sort(zahyouY.begin(), zahyouY.end(), cmpZahyou);
		REP(i, N - 1) {
			int prevIdx = zahyouY[i].first;
			int nextIdx = zahyouY[i + 1].first;
			int kyori = zahyouY[i + 1].second - zahyouY[i].second;
			G[prevIdx].push_back(edge(nextIdx, kyori));
			G[nextIdx].push_back(edge(prevIdx, kyori));
		}
	}

	// プリム法 + プライオリティーキュー
	QWORD ans = 0;
	{
		// 初期化
		priority_queue<P, vector<P>, greater<P>> que;
		vector<bool> isUsed(N, false);
		vector<DWORD> minCost(N, MAX_DWORD);
		que.push(make_pair(0, 0));
		minCost[0] = 0;

		// 実行
		while (!que.empty()) {
			// 一番小さいのからとれる
			P node = que.top();
			que.pop();
			int nodeIdx = node.second;
			int nodeCost = node.first;

			// すでに使用済み
			if (isUsed[nodeIdx]) {
				continue;
			}

			// 頂点採用
			ans += nodeCost;
			isUsed[nodeIdx] = true;

			for (auto egdeOne : G[nodeIdx]) {
				if (minCost[egdeOne.to] > egdeOne.cost) {
					minCost[egdeOne.to] = egdeOne.cost;
					que.push(make_pair(egdeOne.cost, egdeOne.to));
				}
			}
		}
	}

	cout << ans;
	cout << endl;
	return 0;
}
