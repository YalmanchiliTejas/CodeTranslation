#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

int dd[12][12];

vector<tuple<int, int, int> > vv;

int en[12][12];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= a; ++i)
		for (int j = 1; j <= b; ++j)
			cin >> dd[i][j];
	for (int k = 0; k <= 100; ++k)
		for (int x = 0; x + k <= 100; ++x)
			for (int y = 0; x + y + k <= 100; ++y) {
				int fl = 0;
				for (int i = 1; i <= a; ++i)
					for (int j = 1; j <= b; ++j) {
						if (i * x + j * y + k < dd[i][j])
							fl = 1;
					}
				if (fl)
					continue;
				for (int i = 1; i <= a; ++i)
					for (int j = 1; j <= b; ++j) {
						if (!en[i][j] && i * x + j * y + k == dd[i][j])
							en[i][j] = 1, fl = 1;
					}
				if (fl)
					vv.emplace_back(k, x, y);
			}
	for (int i = 1; i <= a; ++i)
		for (int j = 1; j <= b; ++j) {
			if (!en[i][j]) {
				cout << "Impossible\n";
				return 0;
			}
		}
	cout << "Possible\n";
	int n = 202;
	vector<tuple<int, int, string>> ed;
	for (int i = 1; i <= 100; ++i)
		ed.emplace_back(i, i + 1, "X");
	for (int i = 102; i < 202; ++i)
		ed.emplace_back(i, i + 1, "Y");
	for (auto e: vv) {
		int k, x, y;
		tie(k, x, y) = e;
		ed.emplace_back(1 + x, 202 - y, to_string(k));
	}
	cout << n << " " << ed.size() << "\n";
	for (auto e: ed) {
		cout << get<0>(e) << " " << get<1>(e) << " " << get<2>(e) << "\n";
	}
	cout << 1 << " " << 202 << "\n";
	return 0;
}


