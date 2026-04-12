#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vvvll = std::vector<vvll>;
using dd = double;
using vdd = std::vector<dd>;
using vvdd = std::vector<vdd>;
using vvvdd = std::vector<vvdd>;

constexpr ll INF = 1LL << 60;
constexpr ll MOD = (ll)(1e9 + 7);// 998244353L;
constexpr dd EPS = 1e-11;

typedef std::numeric_limits< double > dbl;
//cout.precision(dbl::max_digits10);

//cin,cout高速化のおまじない＋桁数指定
struct Fast{
	Fast(){
		cin.tie(0);
		ios::sync_with_stdio(false);
		cout << fixed << setprecision(std::numeric_limits<double>::max_digits10);
	}
} fast;

#define REPS(i, S, E) for (ll i = (S); i <= (E); i++)
#define REP(i, N) REPS(i, 0, N-1)
#define DEPS(i, E, S) for (ll i = (E); i >= (S); i--)
#define DEP(i, N) DEPS(i, N-1, 0)
#define EACH(e, v) for (auto&& e : v)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }
template<class T> inline T MaxE(vector<T>&v,ll S,ll E){T m=v[S];REPS(i,S,E)chmax(m,v[i]);return m;}//v[S]～v[E]の最大値
template<class T> inline T MinE(vector<T>&v,ll S,ll E){T m=v[S];REPS(i,S,E)chmin(m,v[i]);return m;}//v[S]～v[E]の最小値
template<class T> inline T MaxE(vector<T>&v,ll N) { return MaxE(v, 0, N - 1); } //先頭N個中の最大値
template<class T> inline T MinE(vector<T>&v,ll N) { return MinE(v, 0, N - 1); }
template<class T> inline T MaxE(vector<T>&v) { return MaxE(v, (ll)v.size() ); }
template<class T> inline T MinE(vector<T>&v) { return MinE(v, (ll)v.size() ); }
template<class T> inline ll MaxI(vector<T>&v,ll S,ll E){ll m=S;REPS(i,S,E){if(v[i]>v[m])m=i;}return m;}
template<class T> inline ll MinI(vector<T>&v,ll S,ll E){ll m=S;REPS(i,S,E){if(v[i]<v[m])m=i;}return m;}
template<class T> inline ll MaxI(vector<T>&v,ll N) { return MaxI(v, 0, N - 1); }
template<class T> inline ll MinI(vector<T>&v,ll N) { return MinI(v, 0, N - 1); }
template<class T> inline ll MaxI(vector<T>&v) { return MaxI(v, (ll)v.size() ); }
template<class T> inline ll MinI(vector<T>&v) { return MinI(v, (ll)v.size() ); }
template<class T> inline T Sum(vector<T>&v,ll S,ll E){T s=v[S];REPS(i,S+1,E)s+=v[i];return s;}
template<class T> inline T Sum(vector<T>&v,ll N) { return Sum(v, 0, N - 1); }
template<class T> inline T Sum(vector<T>&v) { return Sum(v, v.size() ); }
template<class T> inline T SumMOD(vector<T>&v,ll S,ll E){T s=v[S];REPS(i,S+1,E)s=(s+v[i])%MOD;return s;}
template<class T> inline T SumMOD(vector<T>&v,ll N) { return SumMOD(v, 0, N - 1); }
template<class T> inline T SumMOD(vector<T>&v) { return SumMOD(v, v.size() ); }

inline ll AddMOD(ll a, ll b) { return (a + b) % MOD; }
inline ll SubMOD(ll a, ll b) { return (a - b + MOD) % MOD; }
inline ll MulMOD(ll a, ll b) { return (a * b) % MOD; }

inline ll in() { ll x; cin >> x; return x; }
inline double inD() { double x; cin >> x; return x; }
inline string inS() { string x; cin >> x; return std::move(x); }
template<class T=ll> inline vector<T> in_v(ll N){vector<T> v(N);REP(i,N)cin>>v[i];return move(v);}
inline void To0origin(vll& v) { EACH(e, v) e--; }

ll N;
vll a;
vvll tbl;

ll rec(ll l, ll r) {
	if (tbl[l][r] != -INF) return tbl[l][r];
	if (l + r == N) return 0;

	ll tmp;
	if ((l + r) % 2 == 0) {//先手番
		tmp = -INF;
		chmax(tmp, rec(l + 1, r) + a[l]);
		chmax(tmp, rec(l, r + 1) + a[N - 1 - r]);
	}
	else {//後手番
		tmp = INF;
		chmin(tmp, rec(l + 1, r) - a[l]);
		chmin(tmp, rec(l, r + 1) - a[N - 1 - r]);
	}
	return tbl[l][r] = tmp;
}


int main()
{
	N = in();
	a = in_v(N);

	tbl.resize(N + 1, vll(N + 1, -INF));

	cout << rec(0, 0) << '\n';
	return 0;
}
