#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (int)(k); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(), a.end()
#define MS(m,v) memset(m,v,sizeof(m))
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

const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
//const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dy[] = { 0, -1, 1, -1, 1, 0, -1, 1 };
bool valid(int x, int y, int h, int w) { return (x >= 0 && y >= 0 && x < h&&y < w); }
int place(int x, int y, int w) { return w*x + y; }

void out(int a)
{
	if (a) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
}

int main()
{
	cin.sync_with_stdio(false); cout << fixed << setprecision(10);
	int h, w;
	cin >> h >> w;
	vs v(h);
	REP(i, h) cin >> v[i];
	int x = 0, y = 0;
	while (1)
	{
		v[x][y] = '.';
		REP(i, 2)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (!valid(nx, ny, h, w)) continue;
			if (v[nx][ny] == '#')
			{
				out(0);
				return 0;
			}
		}
		if (x == h - 1 && y == w - 1) break;
		if (x < h - 1 && y < w - 1 && v[x + 1][y] == '#' && v[x][y + 1] == '#')
		{
			out(0);
			return 0;
		}
		else if (x < h - 1 && v[x + 1][y] == '#')
		{
			x = x + 1, y = y;
			continue;
		}
		else if (y < w - 1 && v[x][y + 1] == '#')
		{
			x = x, y = y + 1;
			continue;
		}
		else assert(false);
	}
	out(1);
	return 0;
}