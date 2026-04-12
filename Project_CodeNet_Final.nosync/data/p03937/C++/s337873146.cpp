#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

const int dx[] = { 0,1 };
const int dy[] = { 1,0 };
bool ans[10][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	rep(i, h) cin >> a[i];
	queue<P> que;
	que.emplace(0, 0);
	ans[0][0] = true;
	while (que.size()) {
		P p = que.front(); que.pop();
		rep(i, 2) {
			int nx = p.first + dx[i], ny = p.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
			if (a[nx][ny] == '.') continue;
			ans[nx][ny] = true;
			que.emplace(nx, ny);
			break;
		}
	}
	bool elf = true;
	rep(i, h)rep(j, w) {
		if (a[i][j] == '#' && !ans[i][j]) elf = false;
	}
	cout << (elf ? "Possible" : "Impossible") << endl;
	return 0;
}
