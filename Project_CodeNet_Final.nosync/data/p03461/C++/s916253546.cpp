#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int A, B;
int d[11][11];
pair<pii, int> info[11][11];

int main() {
	cin >> A >> B;

	for (int i = 1; i <= A; ++i) {
		for (int j = 1; j <= B; ++j) {
			cin >> d[i][j];
		}
	}

	int maxi = 0;
	int u = 0;

	for (int i = 1; i <= A; ++i) {
		for (int j = 1; j <= B; ++j) {
			vector<pii> cand;

			for (int k = 0; k <= 100; ++k) {
				for (int l = 0; l <= 100; ++l) {
					if (k * i + l * j > d[i][j]) continue;
					int c = d[i][j] - k * i - l * j;
					bool ok = 1;

					for (int p = 1; p <= A; ++p) {
						for (int q = 1; q <= B; ++q) {
							if (p * k + q * l + c < d[p][q]) {
								ok = 0;
							}
						}
					}

					if (ok) {
						cand.eb(k, l);
					}
				}
			}

			if (cand.size() == 0) {
				puts("Impossible");
				return 0;
			} else {
				pii la = cand[0];
				u = max(u, la.fi);
				maxi = max(maxi, la.se);
				int zan = d[i][j] - la.fi * i - la.se * j;
				info[i][j] = mp(la, zan);
			}
		}
	}

	puts("Possible");

	vector<pair<pii, int>> vec;

	int S = 0;
	int now = u + 1;

	rep(i, u) {
		vec.eb(mp(i, i + 1), -1);
	}

	int T = now;

	rep(i, maxi) {
		++now;
		vec.eb(mp(now, now - 1), -2);
	}
	++now;

	for (int i = 1; i <= A; ++i) {
		for (int j = 1; j <= B; ++j) {
			pii p = info[i][j].fi;
			int c = info[i][j].se;
			vec.eb(mp(p.fi, now), c);
			vec.eb(mp(now, T + p.se), 0);
			++now;
		}
	}

	cout << now << " " << vec.size() << endl;
	for (auto e : vec) {
		printf("%d %d ", e.fi.fi + 1, e.fi.se + 1);
		if (e.se == -1) {
			putchar('X');
		} else if (e.se == -2) {
			putchar('Y');
		} else {
			printf("%d", e.se);
		}
		puts("");
	}

	cout << S + 1 << " " << T + 1 << endl;

	return 0;
}