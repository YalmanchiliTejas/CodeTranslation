#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (int)(k); i < (int)(n); i++)
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


int n, h, w;

int main()
{
	cin >> n;
	vector<pii> v;
	REP(i, n)
	{
		int a, b; cin >> a >> b;
		v.emplace_back(a, b);
	}
	int fld[4][4];
	REP(i, 4)REP(j, 4)
	{
		char c; cin >> c;
		if (c == 'R') fld[i][j] = 0;
		else if (c == 'G') fld[i][j] = 1;
		else fld[i][j] = 2;
	}
	vi d(1 << 16, INF);
	d[0] = 0;
	queue<int> que;
	que.push(0);
	while (!que.empty())
	{
		int t = que.front(); que.pop();
		if (t == (1 << 16) - 1)
		{
			cout << d[t] << endl;
			break;
		}
		REP(i, n)REP(j, 3)
		{
			int h = v[i].first, w = v[i].second;
			FOR(u, 1 - h, 4)FOR(l, 1 - w, 4)
			{
				int tmp = t;
				FOR(x, max(0, u), min(4, u + h))FOR(y, max(0, l), min(4, l + w ))
				{
					if (fld[x][y] == j)
					{
						tmp |= (1 << (x * 4 + y));
					}
					else
					{
						if ((tmp >> (x * 4 + y)) & 1) tmp ^= (1 << (x * 4 + y));
					}
				}
				if (d[tmp] == INF)
				{
					d[tmp] = d[t] + 1;
					que.push(tmp);
				}
			}
		}
	}
	return 0;
}