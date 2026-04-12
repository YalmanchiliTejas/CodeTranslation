#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp make_pair
#define ERASE(v,i) (v).erase(remove(all(v),i),(v).end())
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define each(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define debug(x) cerr<<#x<<" = "<<(x)<<endl;
#define LINE cerr<<"LINE: "<<__LINE__<<endl;

inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}
template<class T> void preview(T a,T b){for(T it=a;it!=b;++it)cerr<<*it<<" ";cerr<<endl;}

const int INF = 100000000;
const double PI = acos(-1.0), EPS = 1e-10;

int field[128][128];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

inline int dic(P p) {
	return p.first * 100 + p.second;
}

int main() {
	for(int w,h; cin >> w >> h, w || h;) {
		P s, g;
		P ms, mg;
		memset(field, -1, sizeof field);
		int cnt = 0;
		vector<vector<P> > cry(10240);
		rep(y, h) {
			rep(x, w) {
				string c;
				cin >> c;

				if(c == "S") {
					s.first = y;
					s.second = x;
					field[y][x] = 0;
					ms = s;
				}
				else if(c == "G") {
					g.first = y;
					g.second = x;
					mg = g;
				}
				else if(c != ".") {
					int t = toInt(c);
					field[y][x] = t;
					cnt = max(cnt, t);
					cry[t].pb(mp(y, x));
				}
			}
		}
		cry[0].pb(ms);
		field[mg.first][mg.second] = ++cnt;

		vector<vector<P> > D(10240);

		for(int i = 0; i < cnt; i++) {
			rep(num, cry[i].size()) {
				int dist[128][128];
				int tms = 0;
				memset(dist, -1, sizeof dist);
				s = cry[i][num];
				dist[s.first][s.second] = 0;
				queue<P> que;
				que.push(s);
				while(!que.empty()) {
					P p = que.front(); que.pop();
					if(field[p.first][p.second] == i + 1) {
						int t = dist[p.first][p.second];
						D[dic(s)].pb(P(t, dic(p)));
						tms++;
						if(tms == cry[i+1].size()) break;
					}
										rep(j, 4) {
						int ny = p.first + dy[j];
						int nx = p.second + dx[j];
						if(0 <= ny && ny < h && 0 <= nx && nx < w && dist[ny][nx] == -1) {
							dist[ny][nx] = dist[p.first][p.second] + 1;
							que.push(P(ny, nx));
						}
					}
				}
			}
		 }
#if 0
		each(it, dic) {
			printf("(%d,%d) -> #%d\n", it->first.first, it->first.second, it->second);
		}
		debug(idx)
		rep(i,idx) {
			rep(j,idx) {
				if(D[i][j] != INF) printf("%d -> %d = %d\n", i, j, D[i][j]);
			}
		}
#endif

#if 0
		rep(k,idx) rep(i,idx) rep(j,idx) {
			D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
		}
		cout << D[dic[ms]][dic[mg]] << endl;
#endif
		priority_queue<P, vector<P>, greater<P> > que;
		vector<int> fd(10240, INF);
		fd[dic(ms)] = 0;
		que.push(P(0, dic(ms)));
		while(!que.empty()) {
			P p = que.top(); que.pop();
			int v = p.second;
			if(fd[v] < p.first) continue;
			rep(i, D[v].size()) {
				P e = D[v][i];
				if(fd[e.second] > fd[v] + e.first) {
					fd[e.second] = fd[v] + e.first;
					que.push(P(fd[e.second], e.second));
				}
			}
		}
		cout << fd[dic(mg)] << endl;
	}
	return 0;
}