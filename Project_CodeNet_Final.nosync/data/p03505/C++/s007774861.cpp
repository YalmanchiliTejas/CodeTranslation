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

int main()
{
	ll K, A, B;
	cin >> K >> A >> B;
	ll t = A - B;
	if (t <= 0)
	{
		if (A >= K)
		{
			cout << 1 << endl;
		}
		else
		{
			cout << -1 << endl;
		}
		return 0;
	}

	ll n = (K - A) / t;
	if (n*t < K - A)n++;
	cout << 2 * n + 1 << endl;
	return 0;
}