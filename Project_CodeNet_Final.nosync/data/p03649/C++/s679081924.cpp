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
#include<array>
#include<iomanip>
#include<list>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include <queue>
#include<boost/multiprecision/cpp_int.hpp>


using namespace std;
using namespace boost::multiprecision;

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldb = long double;

#define REP(i,a,b) for(ll i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIF(v, n) printf("%."#n"f\n", (double)v)
#define PRIY PRI("Yes")
#define PRIN PRI("No")
template<typename A, typename B>
void mins(A& a, const B& b) { a = min(a, (A)b); };
template<typename A, typename B>
void maxs(A& a, const B& b) { a = max(a, (A)b); };




int main() {
	ll N; cin >> N;
	vector<ll> A(N); REP(i, 0, N)cin >> A[i];
	sort(A.begin(), A.end(), greater<ll>());
	vector<ll> B(N - 1);
	ll ans = 0;
	REP(i, 0, N - 1)B[i] = (A[i] - A[i+1]) / (1 + N);
	REP(i, 0, N) {
		ll sum = 0;
		REP(j, 0, i) sum += (j+1)*B[j];
		REP(j, i, N-1) sum -= (N + 1 - (j + 1)) * B[j];
		A[i] += sum;
	}
		REP(i, 0, N - 1) ans += (i + 1) * B[i];
	ll tmp = A[N - 1] - (N - 1);
	if (tmp > 0) {
		ans += tmp * N;
		REP(i, 0, N) A[i] -= tmp;
	}
	while (true) {
		ll maxind = 0;
		REP(i, 0, N) if (A[maxind] < A[i]) maxind = i;
		if (A[maxind] < N) break;

		A[maxind] -= N;
		REP(i, 0, N) if (i != maxind) ++A[i];

		++ans;
	}
	PRI(ans);
	return 0;
}