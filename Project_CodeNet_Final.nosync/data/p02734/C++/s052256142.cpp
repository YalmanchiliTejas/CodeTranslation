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
	ll N, S;
	cin >> N >> S;
	ll mod = 998244353;
	vector<ll> A(N);
	vector<vector<ll>> dp(N+1);
	REP(i, 0, N)cin >> A[i];
	REP(i, 0, N + 1)dp[i].resize(S + 1, 0);
	REP(i, 1, N + 1) {
		if (A[i - 1] <= S) dp[i][A[i - 1]] += i;
		REP(j, 1, S + 1) {
			if (A[i - 1] + j <= S) dp[i][j + A[i - 1]] += dp[i - 1][j];
			dp[i][j] += dp[i - 1][j];
		}
		REP(j, 1, S + 1) {
			dp[i][j] %= mod;
		}
	}
	ll ans = 0;
	REP(i, 1, N + 1) {
		ans += dp[i][S];
		ans %= mod;
	}
	PRI(ans);
	return 0;
}


