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
using ldouble = long double;


//BDD,ZDD,kdtree, bdtree,bicalc, bolonoy, doloney, tree, chinesemod,segmenttree,daikusutora, saidairyuu, 2bugurahu, heirokenshutu, topologicalsort, kyourenketuseibun

#define REP(i,a,b) for(ll i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIY PRI("Yes")
#define PRIN PRI("No")
#define mins(a,b) a = min(a,(decltype(a))(b))
#define maxs(a,b) a = max(a,(decltype(a))(b))



int main() {
	ll N;
	cin >> N;
	vector<ll> S(N);
	REP(i, 0, N) cin >> S[i];
	vector<vector<ll>> dp(N);
	ll ans = 0;
	REP(c, 1, N) {
		dp[c].push_back(0);
		unordered_set<ll> buf;
		REP(n, 1, N) {
			if (!(n * c < N - 1))break;
			if (buf.count(n * c) > 0 || buf.count(N - 1 - n * c) > 0)break;
			if ((N - 1 - n * c) % c == 0 && !((N - 1 - n * c) / c > n))break;
			if (N - 1 - n * c - c <= 0) break;
			dp[c].push_back(dp[c][n - 1] + S[n * c] + S[N - 1 - n * c]);
			buf.insert(n * c);
			buf.insert(N - 1 - n * c);
			maxs(ans, dp[c].back());
		}
	}
	PRI(ans);
	return 0;
}


