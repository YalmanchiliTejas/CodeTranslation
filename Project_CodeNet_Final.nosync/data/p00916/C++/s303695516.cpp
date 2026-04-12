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

int main() {
	int n;
	while (cin >> n,n) {
		vector<pair<pii, pii>> rect(n);
		vi x;
		vi y;
		REP(i, n) {
			int left, top, right, bottom;
			cin >> left >> top >> right >> bottom;
			rect[i] = { {left,bottom},{right,top} };
			x.push_back(left);
			y.push_back(top);
			x.push_back(right);
			y.push_back(bottom);
		}
		x.push_back(-1);
		y.push_back(-1);
		x.push_back(1000001);
		y.push_back(1000001);
		SORT(x);
		x.erase(unique(x.begin(), x.end()), x.end());
		SORT(y);
		y.erase(unique(y.begin(), y.end()), y.end());
		map<int, int> zipx;
		REP(i, x.size())
			zipx[x[i]] = i;
		map<int, int> zipy;
		REP(i, y.size())
			zipy[y[i]] = i;
		vvb tate(y.size() - 1, vb(x.size(), false));
		vvb yoko(y.size(), vb(x.size() - 1, false));
		REP(i, n) {
			//left
			REP(j, zipy[rect[i].second.second] - zipy[rect[i].first.second]) {
				tate[zipy[rect[i].first.second] + j][zipx[rect[i].first.first]] = true;
			}
			//top
			REP(j, zipx[rect[i].second.first] - zipx[rect[i].first.first]) {
				yoko[zipy[rect[i].second.second]][zipx[rect[i].first.first] + j] = true;
			}
			//right
			REP(j, zipy[rect[i].second.second] - zipy[rect[i].first.second]) {
				tate[zipy[rect[i].first.second] + j][zipx[rect[i].second.first]] = true;
			}
			//bottom
			REP(j, zipx[rect[i].second.first] - zipx[rect[i].first.first]) {
				yoko[zipy[rect[i].first.second]][zipx[rect[i].first.first] + j] = true;
			}
		}
		vvb cell(y.size() - 1, vb(x.size() - 1, false));
		int cnt = 0;
		REP(i, y.size() - 1) {
			REP(j, x.size() - 1) {
				if (!cell[i][j]) {
					cell[i][j] = true;
					cnt++;
					queue<pii> Q;
					Q.push({ i,j });
					while (!Q.empty()) {
						pii q = Q.front();Q.pop();
						
						REP(k, 4) {
							if (WRAP(q.second + dx[k], q.first + dy[k], x.size() - 1, y.size() - 1)) {
								if (!cell[q.first + dy[k]][q.second + dx[k]]) {
									switch (k) {
										case 0:
											if (tate[q.first][q.second] == false) {
												cell[q.first + dy[k]][q.second + dx[k]] = true;
												Q.push({ q.first + dy[k],q.second + dx[k] });
											}
											break;
										case 1:
											if (yoko[q.first + 1][q.second] == false) {
												cell[q.first + dy[k]][q.second + dx[k]] = true;
												Q.push({ q.first + dy[k],q.second + dx[k] });
											}
											break;
										case 2:
											if (tate[q.first][q.second + 1] == false) {
												cell[q.first + dy[k]][q.second + dx[k]] = true;
												Q.push({ q.first + dy[k],q.second + dx[k] });
											}
											break;
										case 3:
											if (yoko[q.first][q.second] == false) {
												cell[q.first + dy[k]][q.second + dx[k]] = true;
												Q.push({ q.first + dy[k],q.second + dx[k] });
											}
											break;
									}
								}
							}
						}
					}
				}
			}
		}
		cout << cnt << endl;
	}
}