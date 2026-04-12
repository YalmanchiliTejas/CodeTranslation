#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define REP(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define each(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define all(v) v.begin(), v.end()
#define mset(a, n) memset(a, n, sizeof(a))

typedef long long ll;

const int INF = 1000000000;
const int MOD = 1000000007;

int main(int argc, char const *argv[])
{
	int H, W; cin >> H >> W;
	vector<string> S(H);
	vector<bool> flg_h(H, false), flg_w(W, false);
	rep(i, H) {
		cin >> S[i];
		rep(j, W) if (S[i][j] == '#') flg_h[i] = true, flg_w[j] = true;
	}

	rep(i, H) {
		if (flg_h[i]) {
			rep(j, W) {
				if (flg_w[j]) cout << S[i][j];
			}
		cout << endl;
		}
	}
	return 0;
}