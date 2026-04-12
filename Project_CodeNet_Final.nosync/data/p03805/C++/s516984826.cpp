#include <bits/stdc++.h>
#define rep(x, to) for (int x = 0; x < (to); x++)
#define REP(x, a, to) for (int x = (a); x < (to); x++)
#define EPS (1e-14)
#define _PA(x,N) rep(i,N){cout<<x[i]<<" ";}cout<<endl;
#define _PA2(x,H,W) rep(i,(H)){rep(j,(W)){cout<<x[i][j]<<" ";}cout<<endl;}

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef complex<double> Complex;
typedef vector< vector<int> > Mat;

ll ans;
int N, M;
int edge[10][10];
vector<int> x;

void solve() {
	for (int i = 2; i <= N; i++) {
		x.push_back(i);
	}
	do {
#if 0
		rep(i, x.size()) {
			cout << x[i] << " ";
		}
		cout << endl;
#endif
		int prev = 1, plus = 1;
		rep(i, x.size()) {
			int cur = x[i];
			if (edge[prev][cur] == 0) {
				plus = 0;
				break;
			}
			prev = cur;
		}
		ans += plus;
	} while (next_permutation(x.begin(), x.end()));
	cout << ans << endl;
}

int main() {
	cin >> N >> M;
	rep(i, M) {
		int a, b;
		cin >> a >> b;
		edge[a][b] = edge[b][a] = 1;
	}
	solve();
	return 0;
}


