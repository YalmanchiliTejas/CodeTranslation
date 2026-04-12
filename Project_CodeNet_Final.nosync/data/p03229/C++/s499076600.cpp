#include "bits/stdc++.h"
#include <boost/range/irange.hpp>
//#include <boost/range/algorithm.hpp>
//#include <boost/multi_array.hpp>
//#include <boost/optional.hpp>

using namespace std;
using boost::irange;

typedef long long           ll;
typedef pair<ll, ll>	    P;

#define ALL(x)              (x).begin(),(x).end()
#define REP(i, n)           for (ll i = 0 ; i < (ll)n ; ++i)
#define REPN(i, m, n)       for (ll i = m ; i < (ll)n ; ++i)
#define INF                 (ll)1e9
#define MOD                 (1000 * 1000 * 1000 + 7)
#define Ceil(x, n)          (((((x))+((n)-1))/n))
#define CeilN(x, n)         (((((x))+((n)-1))/n)*n)
#define FloorN(x, n)        ((x)-(x)%(n))
#define IsOdd(x)            (((x)&0x01UL) == 0x01UL)
#define IsEven(x)           (!IsOdd((x)))
#define M_PI                3.14159265358979323846

/*-----------------------------------------------------------------------------
　処理
 -----------------------------------------------------------------------------*/
static void solve()
{
	ll N;
	cin >> N;
	vector<ll> A(N);
	for (auto i : irange<ll>(0, N)) {
		cin >> A[i];
	}
	sort(ALL(A));
	vector<ll> B = A;
	reverse(ALL(B));

	auto calc = [N](vector<ll> &v) {
		ll ans = 0;
		for (auto i : irange<ll>(0, N - 1)) {
			ans += abs(v[i + 1] - v[i]);
		}
		return ans;
	};

	vector<ll> aft(N);
	ll idx = 0;
	for (auto i : irange<ll>(1, N, 2)) {
		aft[i] = B[idx++];
	}
	idx = 0;
	for (auto i : irange<ll>(2, N, 2)) {
		aft[i] = A[idx++];
	}
	aft[0] = A[Ceil(N, 2) - 1];
	ll ans = calc(aft);

	idx = 0;
	for (auto i : irange<ll>(1, N, 2)) {
		aft[i] = A[idx++];
	}
	idx = 0;
	for (auto i : irange<ll>(2, N, 2)) {
		aft[i] = B[idx++];
	}
	aft[0] = B[Ceil(N, 2) - 1];
	ans = max(ans, calc(aft));

	cout << ans << endl;
}

/*-----------------------------------------------------------------------------
　メイン
 -----------------------------------------------------------------------------*/
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}
