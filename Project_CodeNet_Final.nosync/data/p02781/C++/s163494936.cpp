#include "bits/stdc++.h"
#define FI first.first
#define SE first.second
#define TH second
#define fi first
#define se second
#define th second

using namespace std;

class DebugStream {}LOG;
template <typename T>DebugStream &operator<<(DebugStream &s, const T&) { return s; }
#ifdef DEBUG
#define LOG clog
#endif

typedef long long ll;
typedef pair<ll, ll> ii;
typedef long double ld;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int maxN = 1e2 + 9, maxV = 1e6 + 9, MOD = 1e9 + 7, SQ = 335, lg = 20, bs = 29;

ll gt[maxN][4], eq[maxN][4], sm[maxN][4], k;
string st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cin >> st >> k;
	eq[st.size()][0] = 1;
	for(int i = st.size() - 1; i >= 0; i--) {
		{
			if(st[i] == '0') {
				memcpy(eq[i], eq[i + 1], sizeof eq[i]);
				memcpy(sm[i], sm[i + 1], sizeof sm[i]);
				memcpy(gt[i], gt[i + 1], sizeof gt[i]);
			} else {
				for(int j = 0; j <= k; j++) 
					sm[i][j] += eq[i + 1][j] + sm[i + 1][j] + gt[i + 1][j];
			}
		}

		{
			for(int j = 1; j <= k; j++)
				sm[i][j] += max(0, st[i] - '1') * 
					(eq[i + 1][j - 1] + sm[i + 1][j - 1] + gt[i + 1][j - 1]);
		}

		if(st[i] != '0') {
			for(int j = 1; j <= k; j++) {
				sm[i][j] += sm[i + 1][j - 1];
				gt[i][j] += gt[i + 1][j - 1];
				eq[i][j] += eq[i + 1][j - 1];
			}
		}

		{
			for(int j = 1; j <= k; j++)
				gt[i][j] += max(0, '9' - st[i]) * 
					(eq[i + 1][j - 1] + sm[i + 1][j - 1] + gt[i + 1][j - 1]);

		}
	}
	cout << sm[0][k] + eq[0][k] << '\n';
}
