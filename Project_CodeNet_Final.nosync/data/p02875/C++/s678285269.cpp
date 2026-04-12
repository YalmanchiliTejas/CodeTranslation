#include <bits/stdc++.h>

using namespace std;

template<class T, class U>
void ckmin(T &a, U b)
{
	if (a > b) a = b;
}
template<class T, class U>
void ckmax(T &a, U b)
{
	if (a < b) a = b;
}

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)
#define SZ(x) ((int) ((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define INF 998244353
#define MAXN 10000013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N;
ll ans;
ll fact[MAXN], ifact[MAXN], pw2[MAXN];

ll expo(ll a, ll e)
{
	if (e == 0) return 1;
	if (e & 1)
	{
		return expo(a * a % INF, e >> 1) * a % INF;
	}
	return expo(a * a % INF, e >> 1);
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);
	cerr << fixed << setprecision(4);
	cin >> N;
	fact[0] = 1;
	FOR(i, 1, N + 10)
	{
		fact[i] = fact[i - 1] * i % INF;
	}
	ifact[N + 9] = expo(fact[N + 9], INF - 2);
	FORD(i, N + 9, 0)
	{
		ifact[i] = ifact[i + 1] * (i + 1) % INF;
	}
	pw2[0] = 1;
	FOR(i, 1, N + 10)
	{
		pw2[i] = pw2[i - 1] + pw2[i - 1]; if (pw2[i] >= INF) pw2[i] -= INF;
	}
	N /= 2;
	ans = 1;
	FOR(i, 0, 2 * N)
	{
		ans *= 3; ans %= INF;
	}
	FOR(i, N + 1, 2 * N + 1)
	{
		ans -= 2 * fact[2 * N] * ifact[2 * N - i] % INF * ifact[i] % INF * pw2[2 * N - i];
		ans %= INF;
	}
	if (ans < 0) ans += INF;
	cout << ans << '\n';
	return 0;
}
