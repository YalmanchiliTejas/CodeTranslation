
#define REP(i, t, n)  for (int i = t; i < n; i++)
#define ALL(n)        (n).begin(),(n).end()
#include <limits.h>
#include <stdio.h>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <numeric>

using namespace std;

typedef bool               BOOL;
typedef short              WORD;
typedef unsigned short     U_WORD;
typedef long               DWORD;
typedef unsigned long      U_DWORD;
typedef long long          QWORD;
typedef unsigned long long U_QWORD;

#define N_MAX (100000)

typedef struct distance_x {
	DWORD dwTown;
	QWORD qwCost_X;
	bool operator > (const distance_x& e) const {
		return qwCost_X > e.qwCost_X;
	}
} DIST_X;

typedef struct distance_y {
	DWORD dwTown;
	QWORD qwCost_Y;
	bool operator > (const distance_y& e) const {
		return qwCost_Y > e.qwCost_Y;
	}
} DIST_Y;

typedef struct edge {
	DWORD	dwTo;
	QWORD	qwCost;
	bool operator > (const edge& e) const {
		return qwCost > e.qwCost;
	}
} EDGE;

typedef struct {
	QWORD qwX;
	QWORD qwY;
} POS;

POS  vPosList[N_MAX];
priority_queue<DIST_X, vector<DIST_X>, greater<DIST_X>> que_x;
priority_queue<DIST_Y, vector<DIST_Y>, greater<DIST_Y>> que_y;
priority_queue<EDGE, vector<EDGE>, greater<EDGE>> que_edge;
vector <EDGE> vList[N_MAX];


QWORD prim()
{
	BOOL bUsed[N_MAX] = {};
	
	QWORD qwAns = 0;

	que_edge.push(EDGE{0,0});

	while (!que_edge.empty()) {
		EDGE nowEdge = que_edge.top(); que_edge.pop();
		if (bUsed[nowEdge.dwTo]) continue;
		bUsed[nowEdge.dwTo] = true;
		qwAns += nowEdge.qwCost;

		for (auto iter : vList[nowEdge.dwTo]) {
			que_edge.push(iter);
		}
	}
	return qwAns;
}

void makeEdge()
{
	DWORD dwPreTown;
	dwPreTown = que_x.top().dwTown; que_x.pop();

	while (!que_x.empty()) {
		DIST_X tmpX = que_x.top(); que_x.pop();
		QWORD	qwCost = min(abs(vPosList[dwPreTown].qwX - vPosList[tmpX.dwTown].qwX), abs(vPosList[dwPreTown].qwY - vPosList[tmpX.dwTown].qwY));

		vList[tmpX.dwTown].push_back(EDGE{ dwPreTown , qwCost });
		vList[dwPreTown].push_back(EDGE{ tmpX.dwTown , qwCost });
		
		dwPreTown = tmpX.dwTown;
	}

	dwPreTown = que_y.top().dwTown; que_y.pop();
	while (!que_y.empty()) {
		DIST_Y tmpY = que_y.top(); que_y.pop();
		QWORD  qwCost = min(abs(vPosList[dwPreTown].qwX - vPosList[tmpY.dwTown].qwX), abs(vPosList[dwPreTown].qwY - vPosList[tmpY.dwTown].qwY));

		vList[tmpY.dwTown].push_back(EDGE{ dwPreTown , qwCost });
		vList[dwPreTown].push_back(EDGE{ tmpY.dwTown , qwCost });

		dwPreTown = tmpY.dwTown;
	}

}

void solve_main()
{
	DWORD N;
	cin >> N;


	REP(i, 0, N) {
		QWORD	qwX, qwY;
		cin >> qwX >> qwY;

		vPosList[i].qwX = qwX;
		vPosList[i].qwY = qwY;

		que_x.push(DIST_X{ i,  qwX});
		que_y.push(DIST_Y{ i,  qwY});
	}

	makeEdge();

	cout << prim() << endl;

}

int main()
{
#ifdef FOR_IDE
	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());
#endif

	solve_main();
	return 0;
}
