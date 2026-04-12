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
# define ALL(x)     (x).begin(),(x).end()
# define UNIQ(c)    (c).erase(unique(ALL((c))), end((c)))
# define mp         make_pair
# define eb         emplace_back
# define FOR(i,a,b) for(int i=(a);i<(b);++i)
# define REP(i,n)   FOR(i,0,n)
# define INIT       std::ios::sync_with_stdio(false);std::cin.tie(0);


int main() {
	int N;
	while (cin >> N&&N) {
		//1,0???n???
		stack<pair<int, int>> v;
		int ans = 0;
		int n;
		for (int i = 1; i <= N; i++) {
			cin >> n;
			if (i == 1) {
				if (n == 0) {
					ans++;
					v.push(make_pair(0, 1));
				}
				else {
					v.push(make_pair(1, 1));
				}
			}
			else if (i % 2 == 1) {
				if (n == 0)ans++;
				int t = v.top().first;
				if (n == t) {
					int k = v.top().second;
					v.pop();
					v.push(make_pair(t, k + 1));
				}
				else {
					v.push(make_pair(n, 1));
				}
			}
			else {
				int t = v.top().first;
				if (n == t) {
					if (n == 0)ans++;
					int k = v.top().second;
					v.pop();
					v.push(make_pair(t, k + 1));
				}
				else {
					int k = v.top().second;
					v.pop();
					int k2 = 0;
					if (v.size())k2 += v.top().second, v.pop();
					if (n == 0) {
						ans += k + 1;
					}
					else {
						ans -= k;
					}
					v.push(make_pair(n, k + k2 + 1));
				}
			}
		}
		cout << ans << endl;
	}
}