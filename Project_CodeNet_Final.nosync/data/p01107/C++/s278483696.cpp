#define  _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"
#define int ll

using namespace std;
typedef string::const_iterator State;
#define eps 1e-8L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(20);
}
int grid[100][100];
int ut[10000];
int uf(int now) {
	if (ut[now] == now) return now;
	return ut[now] = uf(ut[now]);
}
int um(int a, int b) {
	a = uf(a);
	b = uf(b);
	if (a == b) return 0;
	ut[a] = b;
	return 1;
}
void solve() {
	while (true) {
		int n, m;
		cin >> n >> m;
		if (n == 0) return;
		REP(i, n) {
			string s;
			cin >> s;
			REP(q, m) {
				if (s[q] == '.')grid[i][q] = 0;
				else grid[i][q] = 1;
			}
		}
		int ok = 1;
		REP(i, n) {
			REP(q, m) {
				if ((i == 0 or  i == n - 1) and (q == 0 or q == m - 1)) continue;
				int memo = grid[i][q];
				{
					grid[i][q] = 1;
					REP(t, n * m) {
						ut[t] = t;
					}
					REP(t, n) {
						REP(p, m) {
							if (grid[t][p] == 1) continue;
							int xe[4] = { 1,-1,0,0 };
							REP(a, 4) {
								int next_x = t + xe[a];
								int next_y = p + xe[3 - a];
								if (next_x >= 0 and next_x < n and next_y >= 0 and next_y < m) {
									if (grid[next_x][next_y] == 0) {
										um(next_x * m + next_y, t * m + p);
									}
								}
							}
						}
					}
					if (uf(0) != uf(m - 1) or uf(0) != uf((n-1) * m + (m-1)) or uf(0) != uf(m * (n - 1))) {
						ok = 0;
						break;
					}
					grid[i][q] = memo;
				}
			}
			if (ok == 0) break;
		}
		if (ok == 1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}
#undef int
int main() {
	init();
	solve();
}
