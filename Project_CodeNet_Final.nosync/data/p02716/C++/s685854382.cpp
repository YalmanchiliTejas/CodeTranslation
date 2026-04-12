
#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<stack>
#include<functional>
#include<string>
#include<cstring>
#include<time.h>
#include<array>
#include<iomanip>
#include<list>
#include<set>
#include<map>
#include<random>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include <queue>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldb = long double;


//BDD,ZDD,kdtree, bdtree,bicalc, bolonoy, doloney, tree, chinesemod,segmenttree,daikusutora, saidairyuu, 2bugurahu, heirokenshutu, topologicalsort, kyourenketuseibun

#define REP(i,a,b) for(ll i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIF(v, n) printf("%."#n"f\n", v)
#define PRIY PRI("Yes")
#define PRIN PRI("No")
#define MINS(a,b) a = min(a,(decltype(a))(b))
#define MAXS(a,b) a = max(a,(decltype(a))(b))



int main() {
	ll N;
	cin >> N;
	vector<ll> A(N+1);
	REP(i, 1, N+1) cin >> A[i];
	vector<unordered_map<ll, ll>> dp(N/2+1);
	dp[1][1] = A[1];
	dp[1][2] = A[2];
	if (N % 2 == 1) dp[1][3] = A[3];
	REP(j, 2, N/2+1) {
		REP(x, 2 * j - 1, N - 2 * (N / 2) + 2 * j + 1) {
			if (x > N) break;
			dp[j][x] = -1e18;
			REP(y, 2 * (j - 1) - 1, N - 2 * (N / 2) + 2 * (j - 1) + 1) {
				if (y > x - 2) break;
				if (dp[j - 1].count(y) == 0) continue;
				else MAXS(dp[j][x], dp[j - 1][y]);
			}
			dp[j][x] += A[x];
		}
	}
	ll ans = -1e18;
	for (auto p : dp[N / 2]) MAXS(ans, p.second);
	PRI(ans);
	return 0;
}