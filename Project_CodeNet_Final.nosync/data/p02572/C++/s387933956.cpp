#include "bits/stdc++.h"
using namespace std;

// 定義
typedef long long         ll;
typedef pair<ll, ll>      P;
#define ALL(x)            (x).begin(),(x).end()
#define REP(i, n)         for(ll i = 0 ; i < (ll)n ; ++i)
#define REPN(i, m, n)     for(ll i = m ; i < (ll)n ; ++i)
#define VL                vector<ll>
#define VVL               vector<vector<ll>>
#define VVVL              vector<vector<vector<ll>>>
#define VC                vector<char>
#define VVC               vector<vector<char>>
#define INF               (ll)2e9
#define INF_LL            1LL<<60
//#define MOD             998244353
#define MOD               1000000007

ll Ceil(ll val, ll div)   { return (val + div - 1) / div; }
ll CeilN(ll val, ll div)  { return Ceil(val, div) * div; }
ll FloorN(ll x, ll n)     { return (x - x % n); }
bool IsOdd(ll x)          { return ((x & 1) == 1); }
bool IsEven(ll x)         { return ((x & 1) == 0); }
template<class T> bool chmax(T& a, T b) { if (a <= b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T& a, T b) { if (a >= b) { a = b; return 1; } return 0; }


// MODのべき乗(n の p乗)
ll powMod(ll n, ll p)
{
	ll res = 1;
	while (p) {
		if (p & 1) (res *= n) %= MOD;
		(n *= n) %= MOD;
		p >>= 1;
	}
	return res;
}

// MODの2のべき乗
ll powMod2(ll p)
{
	return powMod(2, p);
}

// MODの逆元
ll invMod(ll n)
{
	return powMod(n, MOD - 2);
}

void Solve()
{
	ll N;
	cin >>N;
	VL A(N);
	REP(i, N) cin >> A[i];

	ll sum = accumulate(ALL(A), ll(0));
	ll ans = 0;
	REP(i, N) {
		ll sumOne = sum - A[i];
		sumOne %= MOD;
		ll ansOne = sumOne * A[i];
		ansOne %= MOD;
		ans += ansOne;
		ans %= MOD;
	}

	ans = ans * invMod(2);
	ans %= MOD;
	cout << ans << endl;
}

// メイン
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Solve();
	return 0;
}
