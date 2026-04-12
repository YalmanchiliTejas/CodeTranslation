#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(), a.end()
#define MS(m,v) memset(m,v,sizeof(m))
#define D10 fixed<<setprecision(10)
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
const int MOD = 1000000007;
const int INF = MOD + 1;
const ld EPS = 1e-12;
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }

/*--------------------template--------------------*/
const int dx[] = { -1, 0, 0, 1 }, dy[] = { 0, -1, 1, 0 };
//[const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dy[] = { 0, -1, 1, -1, 1, 0, -1, 1 };
bool valid(int x, int y, int h, int w) { return (x >= 0 && y >= 0 && x < h&&y < w); }
int place(int x, int y, int w) { return w*x + y; }


map<int, int> zip;
vi unzip;

typedef pair<pii, pii> rect;

void compress(vi v, map<int,int>& zip, vi& unzip)
{
	sort(ALL(v));
	v.erase(unique(v.begin(), v.end()), v.end());
	unzip.resize(v.size());
	REP(i, v.size())
	{
		zip[v[i]] = i;
		unzip[i] = v[i];
	}
}

void debug(vector<vector<bool>>& v)
{
	REP(i, v.size())
	{
		REP(j, v[i].size()) cout << (v[i][j] ? '#' : '.');
		cout << endl;
	}
}


int main()
{
	int n;
	while (cin >> n, n)
	{
		vector<rect> v;
		vi x, y;
		map<int, int> xzip, yzip;
		vi xunzip, yunzip;
		v.emplace_back(pii(-INF, INF), pii(INF, -INF));
		x.push_back(-INF), x.push_back(INF);
		y.push_back(INF), y.push_back(-INF);
		REP(i, n)
		{
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			v.emplace_back(pii(a, b), pii(c, d));
			x.push_back(a), x.push_back(c);
			y.push_back(b), y.push_back(d);
		}
		compress(x, xzip, xunzip);
		compress(y, yzip, yunzip);
		int h = x.size() * 3, w = y.size() * 3;
		vector<vector<bool>> fld(h, vector<bool>(w));
		REP(i, v.size())
		{
			int lx = xzip[v[i].first.first] * 3, rx = xzip[v[i].second.first] * 3;
			int ty = yzip[v[i].first.second] * 3, by = yzip[v[i].second.second] * 3;
			FOR(i, lx, rx + 1)
			{
				fld[i][ty] = true;
				fld[i][by] = true;
			}
			FOR(i, by, ty + 1)
			{
				fld[lx][i] = true;
				fld[rx][i] = true;
			}
		}
		//debug(fld);
		int ans = 0;
		REP(i, h)REP(j, w)
		{
			if (fld[i][j]) continue;
			ans++;
			queue<pii> que;
			que.push(pii(i, j));
			while (que.size())
			{
				int tmpx = que.front().first, tmpy = que.front().second;
				que.pop();
				fld[tmpx][tmpy] = true;
				REP(k, 4)
				{
					int nx = tmpx + dx[k], ny = tmpy + dy[k];
					if (!valid(nx, ny, h, w)) continue;
					if (!fld[nx][ny])
					{
						fld[nx][ny] = true;
						que.push(pii(nx, ny));
					}
				}
			}
		}
		cout << ans-1 << endl;
	}
	return 0;
}