#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <cassert>
#include <functional>

using namespace std;

#define LOG(...) printf(__VA_ARGS__)
//#define LOG(...)
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).rbegin(),(c).rend())
#define CLR(a) memset((a), 0 ,sizeof(a))
#define WRAP(x,y,w,h) (0<=x && x<w && 0<=y && y<h)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int dx[] = { -1, 0, 1, 0 }; const int dy[] = { 0, 1, 0, -1 };

struct UnionFind {
	vector<int> v;
	UnionFind(int n) : v(n) { for (int i = 0; i < n; i++) v[i] = i; }
	int  find(int x) { return v[x] == x ? x : v[x] = find(v[x]); }
	void unite(int x, int y) { v[find(x)] = find(y); }
};
pii pre[50][50][50][50];
int main() {
	int h, w, m;
	cin >> h >> w >> m;
	vector<string> cell(h);
	REP(i, h)
		cin >> cell[i];
	vector<vvi> ele(3, vvi(h, vi(w)));
	REP(k, 3)
		REP(i, h)
		REP(j, w)
		cin >> ele[k][i][j];
	vector<pii> task(m);
	REP(i, m)
		cin >> task[i].first >> task[i].second;
	
	REP(i, h) {
		REP(j, w) {
			if (cell[i][j] == '.') {
				pre[i][j][i][j] = { i,j };
				queue<pair<pii, pii>> Q;//now pre
				Q.push({ {i,j},{i,j} });
				while (!Q.empty()) {
					pair<pii, pii> q = Q.front();Q.pop();
					int ny = q.first.first;
					int nx = q.first.second;
					int py = q.second.first;
					int px = q.second.second;
					REP(k, 4) {
						if (nx + dx[k] == px&&ny + dy[k] == py)
							continue;
						if (WRAP(nx + dx[k], ny + dy[k], w, h)) {
							if (cell[ny + dy[k]][nx + dx[k]] == '.') {
								pre[i][j][ny + dy[k]][nx + dx[k]]= { ny,nx };
								Q.push({ { ny + dy[k],nx + dx[k] },{ny,nx} });
							}
						}
					}
				}
			}
		}
	}
	int time = 0;
	int idx = 0;
	pii now = task[0];
	vector<vvi> used(h, vvi(w));
	while (1) {
		if (task[idx + 1] == now) {
			idx++;
			if (idx >= m - 1) {
				used[now.first][now.second].push_back(time);
				break;
			}
		}
		used[now.first][now.second].push_back(time);
		time++;
		now = pre[task[idx + 1].first][task[idx + 1].second][now.first][now.second];
	}
	int ans = 0;
	REP(i, h) {
		REP(j, w) {
			if (used[i][j].empty())
				continue;
			bool light = false;
			REP(k, used[i][j].size()) {
				if (!light) {
					ans += ele[1][i][j];
				}
				if (k == used[i][j].size() - 1) {
					ans += ele[2][i][j];
					break;
				}
				if ((used[i][j][k + 1] - used[i][j][k])*ele[0][i][j] < ele[1][i][j] + ele[2][i][j]) {
					ans += (used[i][j][k + 1] - used[i][j][k])*ele[0][i][j];
					light = true;
				}
				else {
					ans += ele[2][i][j];
					light = false;
				}
			}
		}
	}
	cout << ans << endl;
}