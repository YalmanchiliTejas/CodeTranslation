#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <functional>

using namespace std;

typedef long long int ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;

#define FOR(i,n,m) for(ll i=(ll)(m);i<(ll)(n);++i)
#define REP(i,n) FOR(i,n,0)
#define IREP(i,n) for(ll i=(ll)(n);i>=0;--i)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[100005];
ll B[100005];
int main()
{
	int N;
	cin >> N;
	REP(i, N)
	{
		cin >> A[i];
		B[i] = A[i];
	}
	sort(A, A + N);
	sort(B, B + N, [](ll a, ll b) {return a > b; });

	int ai = 1, bi = 0;
	ll l = A[0], r = A[0];
	ll ans = 0;
	while (ai + bi < N)
	{
		ll a = A[ai];
		ll b = B[bi];
		ll ad = std::max(abs(l - a), abs(r - a));
		ll bd = std::max(abs(l - b), abs(r - b));
		if (ad > bd)
		{
			if (abs(l - a) < abs(r - a))
			{
				r = a;
			}
			else
			{
				l = a;
			}
			ai++;
		}
		else
		{
			if (abs(l - b) < abs(r - b))
			{
				r = b;
			}
			else
			{
				l = b;
			}
			bi++;
		}
		ans += std::max(ad, bd);

	}
	cout << ans << endl;
	return 0;
}
