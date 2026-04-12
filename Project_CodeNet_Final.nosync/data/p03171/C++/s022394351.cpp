#include <bits/stdc++.h>
using namespace std;

#define FOR(i, j, n) for (int i(j); i < n; ++i)
#define FORR(v, c) for (auto &v : c)
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define dbg(x) cerr<<#x<<" = " << (x) << endl
#define pnl(x) cout << x << '\n'
#define pns(x) cout << x << ' '
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x, y, z) cin >> x >> y >> z
#define read4(a, b, c, d) cin >> a >> b >> c >> d
#define readv(v) FORR(c,v) read(c)

struct Arrete { int v, c;};
struct Point {int x, y; double distance(Point other) const {return sqrt(SQ(x-other.x)+SQ(y-other.y));}};

typedef	vector<int>	vi;
typedef pair<int,int>	ii;
typedef vector<string>	vs;
typedef vector<ii>	vii;
typedef vector<Arrete>	vg;
typedef vector<long long>	vl;
typedef	long long ll;

const int MAXN = 3000;

ll maximise[MAXN][MAXN];
ll minimise[MAXN][MAXN];
int N;
ll values[MAXN];

void run(int left, int right, int sign)
{
	if (minimise[left][right] != -1) return ;
	if (left == right)
	{
		minimise[left][right] = maximise[left][right] = sign*values[left];
		return ;
	}
	run(left + 1, right, -sign);
	run(left, right - 1, -sign);
	minimise[left][right] = min( sign * values[left] + maximise[left+1][right], 
								sign * values[right] + maximise[left][right - 1]);
	maximise[left][right] = max( sign * values[left] + minimise[left+1][right],
								sign * values[right] + minimise[left][right-1]);
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	FOR(i,0, MAXN) FOR(j,0, MAXN) maximise[i][j] = minimise[i][j] = -1;

	read(N);
	FOR(i,0,N) read(values[i]);
	run(0, N-1, 1);
	pnl(maximise[0][N-1]);
}

