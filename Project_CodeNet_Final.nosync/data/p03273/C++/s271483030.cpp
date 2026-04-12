#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

	int h, w;
	cin >> h >> w;

	vector<string> v(h);
	vector<int> h_ng(h, 0);
	vector<int> w_ng(w, 0);
	rep (i, 0, h)
		cin >> v[i];

	rep (i, 0, h) {
		bool judge = false;
		rep (j, 0, w) {
			if (v[i][j] == '#') {
				judge = true;
				break;
			}
		}
		if (!judge)
			h_ng[i] = 1;
	}

	rep (i, 0, w) {
		bool judge = false;
		rep (j, 0, h) {
			if (v[j][i] == '#') {
				judge = true;
				break;
			}
		}
		if (!judge)
			w_ng[i] = 1;
	}

	rep (i, 0, h) {
		if (h_ng[i])
			continue;
		rep (j, 0, w) {
			if (w_ng[j])
				continue;

			cout << v[i][j];
		}
		cout << "\n";
	}

	return 0;
}
