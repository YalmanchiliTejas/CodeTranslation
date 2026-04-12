#define  _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144*2LL
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

unsigned long xor128() {
	static unsigned long x = 123456789, y = 362436069, z = 521288629, w = time(NULL);
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(20);
}

#define int ll
void solve(){
	while (true) {
		string s;
		cin >> s;
		if (s == "#") return;
		s.push_back('/');
		int grid[10][10] = {};
		int x = 0;
		int w = 0;
		string b;
		REP(i, s.length()) {
			if (s[i] == '/') {
				int y = 0;
				REP(q, b.length()) {
					if (b[q] == 'b') {
						grid[x][y] = 1;
						y++;
					}
					else {
						y += b[q] - '0';
					}
				}
				w = y;
				b.clear();
				x++;
			}
			else {
				b.push_back(s[i]);
			}
		}
		{
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			a--; b--; c--; d--;
			assert(grid[a][b] == 1);
			grid[a][b] = 0;
			assert(grid[c][d] == 0);
			grid[c][d] = 1;
		}
		REP(i, x) {
			if (i != 0) cout << "/";
			int cnter = 0;
			REP(q, w) {
				if (grid[i][q] == 1) {
					if (cnter != 0) {
						cout << cnter;
					}
					cnter = 0;
					cout << "b";
				}
				else {
					cnter++;
				}
			}
			if (cnter != 0) cout << cnter;
		}
		cout << endl;
	}
}

#undef int
int main() {
	init();
	solve();
}
