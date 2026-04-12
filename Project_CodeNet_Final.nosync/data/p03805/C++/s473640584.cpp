#include "bits/stdc++.h"

using namespace std;
using ll = long long int;
using ullong = unsigned long long;
#define rep(i,n) for(int i = 0; i < n; i++)
#define FOR(i, a, b)  for(int i = (a); i < (b) ; i++)
#define pb push_back
#define SORT(v,n) sort(v, v+n)
#define ALL(x) (x).begin(),(x).end()
#define debug(x) cerr << #x << ": " << x << '\n'
#define int ll
 int INF = 1e9;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
typedef pair<int, int> Vec2;
const int dx[8] = { 1, 0, -1, 0, 1, -1, -1, 1 };
const int dy[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int d[500][500];

const int MAX_N = 8;
bool used[MAX_N];
int perm[MAX_N];
bool G[MAX_N][MAX_N];
int ans = 0;

void permutation1(int pos, int n) {
	if (pos == n) {
		if (perm[0] != 0) return;
		rep(i, n-1) {
			int a = perm[i];
			int b = perm[i + 1];
			if (!G[a][b]) return;
		}
		ans++;
		return;
	}
	rep(i, n) {
		if (!used[i]) {
			perm[pos] = i;
			used[i] = true;
			permutation1(pos + 1, n);
			used[i] = false;
		}
	}
	return;
}

signed main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >>  m;
	rep(i, MAX_N) {
		rep(j, MAX_N) G[i][j] = false;
	}
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		G[a][b] = true;
		G[b][a] = true;
	}
	rep(i,MAX_N) used[i] = false;
	permutation1(0,n);
	cout << ans << endl;
	return 0;
}
