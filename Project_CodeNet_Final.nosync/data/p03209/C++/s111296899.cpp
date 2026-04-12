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

ll T[55], P[55];

ll sum(int n,ll x)
{
	if (x == 0)
	{
		return 0;
	}
	if (n == 0)
	{
		return 1;
	}

	ll s = 0;
	x--;
	if (x <= T[n - 1])
	{
		return sum(n - 1, x);
	}
	x -= T[n - 1]+1;
	s += P[n - 1]+1;
	if (x <= T[n - 1])
	{
		return s + sum(n - 1, x);
	}
	return s + P[n - 1];
}

int main()
{
	int N;
	ll X;
	cin >> N >> X;
	
	T[0] = P[0] = 1;
	FOR(i, N + 1, 1)
	{
		T[i] = 2 * T[i - 1] + 3;
		P[i] = 2 * P[i - 1] + 1;
	}

	cout << sum(N, X) << endl;
	return 0;
}