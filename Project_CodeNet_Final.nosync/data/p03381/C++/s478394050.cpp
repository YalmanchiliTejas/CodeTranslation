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
# include <cstdlib>
# include <tuple>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr int INF = 2147483647;
constexpr int HINF = INF / 2;
constexpr double DINF = 100000000000000000.0;
constexpr double HDINF = 50000000000000000.0;
constexpr long long LINF = 9223372036854775807;
constexpr long long HLINF = 4500000000000000000;
const double PI = acos(-1);
template <typename T_char>T_char TL(T_char cX) { return tolower(cX); };
template <typename T_char>T_char TU(T_char cX) { return toupper(cX); };
const int vy[] = { -1, -1, -1, 0, 1, 1, 1, 0 }, vx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
const int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
# define ALL(x)      (x).begin(),(x).end()
# define UNIQ(c)     (c).erase(unique(ALL((c))),(c).end())
# define LOWER(s)    transform(ALL((maze)),(maze).begin(),TL<char>)
# define UPPER(s)    transform(ALL((maze)),(maze).begin(),TU<char>)
# define FOR(i,a,b)  for(LL i=(a);i<(b);i++)
# define RFOR(i,a,b) for(LL i=(a);i>=(b);i--)
# define REP(i,n)    FOR(i,0,n)
# define INIT        std::ios::sync_with_stdio(false);std::cin.tie(0)

int n;
int x[202020];
int sorter[202020];
bool calc(int a, int b) {
	return x[a] < x[b];
}
int ans[202020];
int main() {
	cin >> n;
	REP(i, n)cin >> x[i];
	REP(i, n)sorter[i] = i;
	sort(sorter, sorter + n, calc);
	REP(i, n) {
		if ((i + 1)*2 <= n) {
			ans[sorter[i]] = x[sorter[n / 2]];
		}
		else {
			ans[sorter[i]] = x[sorter[n / 2 - 1]];
		}
	}
	REP(i, n) {
		cout << ans[i] << endl;
	}
	//system("pause");
}