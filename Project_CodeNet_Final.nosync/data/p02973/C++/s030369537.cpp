#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define REP(i, n) for(ll i = 0LL; i < (ll)(n); i++)
#define REPR(i, n) for(ll i = n-1; i >= 0LL; i--)
#define FOR(i, n, m) for(ll i = n; i < (ll)(m); i++)
#define PRINT(x) cout << x << endl
#define ALL(v) v.begin(), v.end()
#define INF (ll)1e18
#define INFD 1e18
#define PI 3.14159265358979
#define MOD 1000000007
#define vl vector<ll>

vector<ll> dx = {-1, 1, 0, 0};
vector<ll> dy = {0, 0, 1, -1};

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }


int main()
{
	ll N;
	cin >> N;

	vector<ll> A(N);
	REP(i, N) cin >> A[i];
	reverse(ALL(A));

	vector<ll> dp(N, INF);
	REP(i, N) {
		*upper_bound(ALL(dp), A[i]) = A[i];
	}
	auto iter = lower_bound(ALL(dp), INF);
	PRINT(distance(dp.begin(), iter));
	return 0;
}
