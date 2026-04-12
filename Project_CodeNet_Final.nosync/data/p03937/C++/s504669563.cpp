#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	int h, w;
	cin >> h >> w;
	vector<string> v(h);
	rep(i,h) cin >> v[i];
	int cnt = 0;
	rep(i,h) rep(j,w) if (v[i][j] == '#') cnt++;
	if (cnt == h + w - 1) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
}

int main() {
	solve();
	return 0;
}