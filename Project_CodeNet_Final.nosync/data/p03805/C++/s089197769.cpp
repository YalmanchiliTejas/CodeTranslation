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
# include <random>
# include <chrono>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<LL, LL> P;
constexpr int INF = 2000000000;
constexpr int HINF = INF / 2;
constexpr double DINF = 100000000000000000.0;
constexpr long long LINF = 9223372036854775807;
constexpr long long HLINF = 4500000000000000000;
const double PI = acos(-1);
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
# define ALL(x)      (x).begin(),(x).end()
# define UNIQ(c)     (c).erase(unique(ALL((c))),(c).end())
# define mp          make_pair
# define eb          emplace_back
# define FOR(i,a,b)  for(int i=(a);i<(b);i++)
# define RFOR(i,a,b) for(int i=(a);i>=(b);i--)
# define REP(i,n)    FOR(i,0,n)
# define INIT        std::ios::sync_with_stdio(false);std::cin.tie(0)

int G[12][12];
int n, m;
int ans = 0;

int main() {
	cin >> n >> m;
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		G[a][b] = G[b][a] = true;
	}
	vector<int> v;
	REP(i, n)v.emplace_back(i + 1);
	do {
		if (v[0] != 1)continue;
		bool used[12] = {};
		REP(i, n) {
			used[v[i]] = true;
			if (i) {
				if (!G[v[i - 1]][v[i]])break;
			}
			if (i == n - 1) {
				REP(j, n) {
					if (!used[j + 1])break;
					if (j == n - 1) {
						ans++;
					}
				}
			}
		}

	} while (next_permutation(ALL(v)));
	cout << ans << endl;
}