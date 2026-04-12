#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include "bits/stdc++.h"
#define REP(i,a,b) for(int i=a;i<b;++i)
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define ALL(a) begin(a),end(a)
#define ifnot(a) if(not (a))
#define dump(x)  cerr << #x << " = " << (x) << endl
using namespace std;

// #define int ll
#ifdef _MSC_VER
const bool test = true;
#else 
const bool test = false;
#endif

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
#define INF (1 << 28)
ull mod = (int)1e9 + 7;
//.....................
const int MAX = (int)2e5 + 5;

char field[10][10];
bool visited[10][10];
bool possible = false;
int ans_cnt = 0;
struct Point {
	int y, x, cnt;
};

int H, W;

bool ng(int y, int x) {
	return y < 0 || H <= y || x < 0 || W <= x;
}

void grid_dfs(Point now) {
	int i, j;/*
	dump(now.y);
	dump(H - 1);
	dump(now.x);
	dump(W - 1);
	dump(now.cnt);
	dump(ans_cnt);*/
	if (now.y == H - 1 && now.x == W - 1) {
		if (now.cnt == ans_cnt) possible = true;
		else dump(now.cnt);
	}
	Point next = now;
	next.cnt++;
	rep(i, 2) {
		next.y = now.y + dy[i];
		next.x = now.x + dx[i];
		if (ng(next.y, next.x)) continue;
		if (visited[next.y][next.x]) continue;
		if (field[next.y][next.x] == '#') {
			field[next.y][next.x] = 'x';
			grid_dfs(next);
			field[next.y][next.x] = '#';
		}
	}
}

int main() {
	//.............
	cin >> H >> W;
	rep(i, H) {
		cin >> field[i];
	}
	//..............
	rep(i, H) rep(j, W) {
		if (field[i][j] == '#') ans_cnt++;
	}
	dump(ans_cnt);
	grid_dfs({ 0,0,1 });
	if (field[0][0] != '#') possible = false;
	puts(possible ? "Possible" : "Impossible");
	return 0;
}