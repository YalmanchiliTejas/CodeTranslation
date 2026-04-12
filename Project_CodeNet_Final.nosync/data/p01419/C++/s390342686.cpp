#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <cctype>
#include <tuple>
#include <array>

// BEGIN CUT HERE
#ifdef _MSC_VER
#include <agents.h>
#endif
// END CUT HERE 

#define FOR(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define REV(v) v.rbegin(), v.rend()
#define UNIQUE(v) v.erase(unique(ALL(v)), v.end())
#define MEMSET(v, s) memset(v, s, sizeof(v))
#define MP make_pair
#define MT make_tuple

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef unsigned long long ull;

const int N = 55;
int a[3][N][N];
string v[N];

vector<int> t[N][N];
P prv[N][N];
int dist[N][N];

int dr[] = { 0, 1, 0, -1 };
int dc[] = { -1, 0, 1, 0, -1 };

int r, c, m;

int bfs(P start, P goal, int base){
	MEMSET(dist, -1);

	dist[start.first][start.second] = base;
	queue<P> q;
	q.push(start);

	while (!q.empty()){
		auto p = q.front();
		q.pop();

		rep(d, 4){
			int nr = p.first + dr[d], nc = p.second + dc[d];
			if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
			if (v[nr][nc] == '#') continue;
			if (dist[nr][nc] >= 0) continue;
			dist[nr][nc] = dist[p.first][p.second] + 1;
			prv[nr][nc] = MP(p.first, p.second);
			q.push(MP(nr, nc));
		}
	}

	P pos = goal;
	while (pos != start){
		t[pos.first][pos.second].push_back(dist[pos.first][pos.second]);
		pos = prv[pos.first][pos.second];
	}
	return dist[goal.first][goal.second];
}


int main(){
	ios::sync_with_stdio(false);
	cin >> r >> c >> m;
	rep(i, r) cin >> v[i];
	rep(k, 3) rep(i, r) rep(j, c) cin >> a[k][i][j];

	P prv;
	int d = 0;
	rep(i, m){
		P p;
		cin >> p.first >> p.second;
		if (i) d = bfs(prv, p, d);
		else t[p.first][p.second].push_back(0);
		prv = p;
	}

	ll ans = 0;
	rep(i, r) rep(j, c){
		int cost = 0, prv = -1;
		for (auto e : t[i][j]){
			if (prv < 0) cost = a[1][i][j] + a[2][i][j];
			else cost = min(cost + a[1][i][j] + a[2][i][j], cost + (e - prv)*a[0][i][j]);
			prv = e;
		}
		ans += cost;
	}
	cout << ans << endl;

	return 0;
}