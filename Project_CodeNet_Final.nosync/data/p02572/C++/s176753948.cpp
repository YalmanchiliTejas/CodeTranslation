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
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<bitset>
#include <queue>
#include <map>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldouble = long double;


//BDD,ZDD,kdtree, bdtree,bicalc, bolonoy, doloney, tree, chinesemod,segmenttree,daikusutora, saidairyuu, 2bugurahu, heirokenshutu, topologicalsort, kyourenketuseibun

#define REP(i,a,b) for(int i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIY PRI("Yes")
#define PRIN PRI("No")



int main() {
	ll mod = 1000000007;
	int N;
	cin >> N;
	vector<ll> A(N+1);
	vector<ll> B(N+1);
	REP(i, 1, N + 1) cin >> A[i];
	B[N] = 0;
	for (int i = N - 1; i >= 1; --i) B[i] = (B[i + 1] + A[i + 1]) % mod;
	ll ans = 0;
	REP(i, 1, N) {
		ans += A[i] * B[i];
		ans %= mod;
	}
	PRI(ans);
	return 0;
}


