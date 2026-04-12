# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <tuple>
# include <unordered_map>
# include <numeric>
# include <complex>
# include <bitset>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<LL, LL> P;
constexpr int INF = 2000000000;
constexpr int HINF = INF / 2;
constexpr double DINF = 100000000000000000.0;
constexpr long long LINF = 9223372036854775807;
constexpr long long HLINF = 4500000000000000000;
constexpr long long MMOD = 500000004;
const double PI = acos(-1);
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
# define ALL(x)      (x).begin(),(x).end()
# define UNIQ(c)     (c).erase(unique(ALL((c))), end((c)))
# define mp          make_pair
# define eb          emplace_back
# define FOR(i,a,b)  for(int i=(a);i<(b);i++)
# define RFOR(i,a,b) for(int i=(a);i>=(b);i--)
# define REP(i,n)    FOR(i,0,n)
# define INIT        std::ios::sync_with_stdio(false);std::cin.tie(0)

const int MOD = 1e9 + 7;
vector<P>g[110000];
int v[110000];
LL ijk_L[110000];
LL ijk_R[110000];

LL L[110000];
LL R[110000];
int main() {
	int n, m;
	cin >> n >> m;
	int s, t;
	cin >> s >> t;
	s--; t--;
	for (int i = 0; i < m; i++) {
		int p, q, r;
		cin >> p >> q >> r;
		p--; q--;
		g[p].emplace_back(mp(q, r));
		g[q].emplace_back(mp(p, r));
	}
	for (int i = 0; i < n; i++) {
		ijk_L[i] = LINF;
	}
	ijk_L[s] = 0;
	priority_queue<P> Q;
	Q.push(mp(0LL, s));
	L[s] = 1;
	while (Q.size()) {
		LL cost = -Q.top().first;
		int at = Q.top().second;
		Q.pop();
		if (v[at])continue;
		v[at] = 1;
		for (int i = 0; i < g[at].size(); i++) {
			int to = g[at][i].first;
			LL tmp = cost + g[at][i].second;
			if (!v[to] && ijk_L[to] >= tmp) {
				if (ijk_L[to] > tmp) {
					ijk_L[to] = tmp;
					L[to] = L[at];
					Q.push(mp(-ijk_L[to], to));
				}
				else {
					L[to] = (L[to] + L[at]) % MOD;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		ijk_R[i] = LINF;
		v[i] = 0;
	}
	ijk_R[t] = 0;
	R[t] = 1;
	Q.push(mp(0LL, t));
	while (Q.size()) {
		LL cost = -Q.top().first;
		int at = Q.top().second;
		Q.pop();
		if (v[at])continue;
		v[at] = 1;
		for (int i = 0; i < g[at].size(); i++) {
			int to = g[at][i].first;
			LL tmp = cost + g[at][i].second;
			if (!v[to] && ijk_R[to] >= tmp) {
				if (ijk_R[to] > tmp) {
					ijk_R[to] = tmp;
					R[to] = R[at];
					Q.push(mp(-ijk_R[to], to));
				}
				else {
					R[to] = (R[to] + R[at]) % MOD;
				}
			}
		}
	}
	LL D = ijk_L[t];
	LL ret = L[t] * R[s] % MOD;
	LL ng = 0;
	for (int i = 0; i < n; i++) {
		if (ijk_L[i] + ijk_R[i] > D)continue;
		if (ijk_L[i] == ijk_R[i]) {
			ng = (ng + L[i] * R[i] % MOD*L[i] % MOD*R[i]) % MOD;
		}
		for (int j = 0; j < g[i].size(); j++) {
			if (ijk_L[i] + g[i][j].second + ijk_R[g[i][j].first] == D) {
				if ((ijk_L[g[i][j].first] > ijk_R[g[i][j].first]) && (ijk_L[i] < ijk_R[i])) {
					ng = (ng + L[i] * R[g[i][j].first] % MOD*L[i] % MOD*R[g[i][j].first]) % MOD;
				}
			}
		}
	}
	ret = (ret + MOD - ng) % MOD;
	cout << ret << endl;
}