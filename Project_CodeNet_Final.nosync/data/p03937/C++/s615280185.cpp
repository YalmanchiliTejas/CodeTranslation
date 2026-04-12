#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

const int dx[] = { 0,1 };
const int dy[] = { 1,0 };
char mp[10][10];
bool used[10][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h, w;
	cin >> h >> w;
	rep(i, h)rep(j, w) cin >> mp[i][j];
	queue<P> que;
	que.emplace(0, 0);
	memset(used, 0, sizeof(used));
	while (que.size()) {
		P p = que.front(); que.pop();
		used[p.first][p.second] = true;
		rep(i, 2) {
			int a = p.first + dx[i], b = p.second + dy[i];
			if (a < 0 || b < 0 || a >= h || b >= w) continue;
			if (mp[a][b] == '.') continue;
			que.emplace(a, b);
			break;
		}
	}
	bool ok = true;
	rep(i, h)rep(j, w) if (mp[i][j] == '#' && !used[i][j]) ok = false;
	if (ok) printf("%s\n", "Possible");
	else printf("%s\n", "Impossible");
	return 0;
}
