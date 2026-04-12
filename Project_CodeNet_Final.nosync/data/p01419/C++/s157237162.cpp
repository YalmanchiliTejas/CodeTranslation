#include<iostream>
#include<sstream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, -1, 0, 1};
vi v[50][50];
int h, w, m;
int a[50][50], b[50][50], c[50][50], dir[50][50][50][50];
char in[50][51];

void rec(int y, int x, int sy, int sx, int py, int px){
	rep(d, 4){
		int ny = y + dy[d], nx = x + dx[d];
		if(ny == py && nx == px) continue;
		if(ny < 0 || nx < 0 || ny >= h || nx >= w || in[ny][nx] == '#') continue;
		dir[ny][nx][sy][sx] = d;
		rec(ny, nx, sy, sx, y, x);
	}
}
int dp[2000][2];
int calc(const vi &v, int y, int x){
	int n = v.size();
	if(n == 1) return b[y][x] + c[y][x];
	rep(i, n) rep(j, 2) dp[i][j] = inf;
	dp[0][0] = b[y][x] + c[y][x];
	dp[0][1] = b[y][x];
	
	rep(i, n - 1) rep(j, 2) if(dp[i][j] < inf) rep(k, 2){
		int nxt = dp[i][j];
		nxt += j ? (v[i + 1] - v[i]) * a[y][x] : b[y][x];
		if(!k) nxt += c[y][x];
		
		dp[i + 1][k] = min(dp[i + 1][k], nxt);
	}
	return dp[n - 1][0];
}
int main(){
	cin >> h >> w >> m;
	rep(i, h) cin >> in[i];
	rep(i, h) rep(j, w) cin >> a[i][j];
	rep(i, h) rep(j, w) cin >> b[i][j];
	rep(i, h) rep(j, w) cin >> c[i][j];
	rep(i, h) rep(j, w) if(in[i][j] == '.') rec(i, j, i, j, i, j);
	
	int ny, nx, y, x, t = 0;
	cin >> y >> x;
	v[y][x].pb(t);
	rep(i, m - 1){
		cin >> ny >> nx;
		do{
			int d = dir[y][x][ny][nx];
			y -= dy[d]; x -= dx[d];
			v[y][x].pb(++t);
		}while(ny != y || nx != x);
	}
	int ans = 0;
	rep(i, h) rep(j, w) if(v[i][j].size()) ans += calc(v[i][j], i, j);
	cout << ans << endl;
	return 0;
}