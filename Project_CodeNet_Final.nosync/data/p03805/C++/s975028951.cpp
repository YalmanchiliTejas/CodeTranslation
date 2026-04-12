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
using namespace std;
using LL = long long;
using ULL = unsigned long long;

constexpr int INF = 2000000000;
constexpr int HINF = INF / 2;
constexpr double DINF = 100000000000000000.0;
constexpr long long LINF = 9223372036854775807;
constexpr long long HLINF = 4500000000000000000;
const double PI = acos(-1);
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
#define ALL(x)    (x).begin(),(x).end()
#define UNIQ(c)   (c).erase(unique(ALL((c))), end((c)))
#define mp        make_pair
#define eb        emplace_back
#define REP(i, a) for (int i = 0; i < (a); i++)

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> G[100];
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	vector<int> v;
	for (int i = 0; i < n; i++) {
		v.emplace_back(i + 1);
	}
	int ans = 0;
	do {
		if (v[0] != 1)continue;
		int count = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < G[v[i]].size(); j++) {
				if (G[v[i]][j] == v[i + 1])count++;
			}
		}
		if (count == n - 1)ans++;
	} while (next_permutation(ALL(v)));
	cout << ans << endl;
}