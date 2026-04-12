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
constexpr dd EPS = 1e-11;

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
#define DEPS(i, S, E) for (ll i = (E); i >= (S); i--)
#define DEP(i, N) DEPS(i, 0, N-1)
#define EACH(e, v) for (auto&& e : v)

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; }return false; }
template<class T> inline T MaxE(vector<T>&v,ll S,ll E){T m=v[S]; REPS(i,S,E)chmax(m,v[i]); return m;}//v[S]～v[E]の最大値
template<class T> inline T MinE(vector<T>&v,ll S,ll E){T m=v[S]; REPS(i,S,E)chmin(m,v[i]); return m;}//v[S]～v[E]の最小値
template<class T> inline T MaxE(vector<T> &v, ll N) { return MaxE(v, 0, N - 1); } //先頭N個中の最大値
template<class T> inline T MinE(vector<T> &v, ll N) { return MinE(v, 0, N - 1); }
template<class T> inline T MaxE(vector<T> &v) { return MaxE(v, (ll)v.size()); }
template<class T> inline T MinE(vector<T> &v) { return MinE(v, (ll)v.size()); }
template<class T> inline ll MaxI(vector<T>&v,ll S,ll E){ll m=S; REPS(i,S,E){if(v[i]>v[m])m=i;} return m;}
template<class T> inline ll MinI(vector<T>&v,ll S,ll E){ll m=S; REPS(i,S,E){if(v[i]<v[m])m=i;} return m;}
template<class T> inline ll MaxI(vector<T> &v, ll N) { return MaxI(v, 0, N - 1); }
template<class T> inline ll MinI(vector<T> &v, ll N) { return MinI(v, 0, N - 1); }
template<class T> inline ll MaxI(vector<T> &v) { return MaxI(v, (ll)v.size()); }
template<class T> inline ll MinI(vector<T> &v) { return MinI(v, (ll)v.size()); }
template<class T> inline T Sum(vector<T> &v, ll S, ll E){ T s=v[S]; REPS(i, S+1, E)s+=v[i]; return s; }
template<class T> inline T Sum(vector<T> &v, ll N) { return Sum(v, 0, N - 1); }
template<class T> inline T Sum(vector<T> &v) { return Sum(v, v.size()); }
ll MSB(ll a){for(ll o=63,x=-1;;){ll m=(o+x)/2; if(a<(1LL<<m))o=m; else x=m; if(o-x==1)return x;}}

template<class T=ll> inline vector<T> cinv(ll N){ vector<T> v(N); REP(i, N)cin>>v[i]; return move(v);}
template<class T=ll, class S=ll> inline vector<pair<T, S>> cinv2(ll N){
	vector<pair<T, S>> v(N); REP(i,N){cin>>v[i].first>>v[i].second;} return move(v); }
template<class T=ll,class S=ll,class R=ll> inline vector<tuple<T, S, R>> cinv3(ll N){
	vector<tuple<T,S,R>> v(N); REP(i,N){cin>>get<0>(v[i])>>get<1>(v[i])>>get<2>(v[i]);} return move(v);}
template<class T=ll,class S=ll,class R=ll,class Q=ll> inline vector<tuple<T,S,R,Q>> cinv4(ll N){
	vector<tuple<T,S,R,Q>> v(N); REP(i,N){cin>>get<0>(v[i])>>get<1>(v[i])>>get<2>(v[i])>>get<3>(v[i]);} return move(v);}
template<class T> inline void coutv(vector<T> &v, char deli=' '){
	ll N=(ll)v.size(); REP(i,N){cout << v[i] << ((i==N-1)?'\n':deli);} }

constexpr ll MOD = (ll)(1e9 + 7); //998244353LL;// (ll)(1e9 + 7);
template<int mod> struct Modll{
	ll val;
	Modll(ll v = 0): val(v %mod){ if (val < 0) val += mod; }
	Modll operator - () { return -val; }
	Modll operator + (const Modll &b) const { return val + b.val; }
	Modll operator - (const Modll &b) const { return val - b.val; }
	Modll operator * (const Modll &b) const { return val * b.val; }
	Modll operator / (const Modll &b) const { return Modll(*this) /= b; }
	Modll operator + (ll b) const { return *this + Modll(b); }
	Modll operator - (ll b) const { return *this - Modll(b); }
	Modll operator * (ll b) const { return *this * Modll(b); }
	friend Modll<mod> operator + (ll a, const Modll<mod> &b) { return b + a; }
	friend Modll<mod> operator - (ll a, const Modll<mod> &b) { return -b + a; }
	friend Modll<mod> operator * (ll a, const Modll<mod> &b) { return b * a; }
	Modll &operator += (const Modll &b) { val=(val+b.val)%mod; return *this; }
	Modll &operator -= (const Modll &b) { val=(val+mod-b.val)%mod; return *this; }
	Modll &operator *= (const Modll &b) { val=(val*b.val)%mod; return *this; }
	Modll &operator /= (const Modll &b) {
		ll c=b.val, d=mod, u=1, v=0;
		while (d){
			ll t = c / d;
			c -= t * d; swap(c, d);
			u -= t * v; swap(u, v);
		}
		val = val * u % mod;
		if (val < 0) val += mod;
		return *this;
	}
	Modll &operator += (ll b) { return *this += Modll(b); }
	Modll &operator -= (ll b) { return *this -= Modll(b); }
	Modll &operator *= (ll b) { return *this *= Modll(b); }
	Modll &operator /= (ll b) { return *this /= Modll(b); }
	bool operator == (const Modll &b) { return val == b.val; }
	bool operator != (const Modll &b) { return val != b.val; }
	bool operator == (ll b) { return *this == Modll(b); }
	bool operator != (ll b) { return *this != Modll(b); }
	friend bool operator == (ll a, const Modll<mod> &b) { return Modll<mod>(a) == b.val; }
	friend bool operator != (ll a, const Modll<mod> &b) { return Modll<mod>(a) != b.val; }
	friend ostream &operator << (ostream &os, const Modll<mod> &a) { return os << a.val; }
	friend istream &operator >> (istream &is, const Modll<mod> &a) { return is >> a.val; }
	static Modll Combination(ll a, ll b){
		chmin(b, a-b);
		Modll c = 1;
		REP(i, b) c *= a-i;
		REP(i, b) c /= i+1;
		return c;
	}
	Modll pow(ll n){
		if (n == 0) return 1;
		auto b = pow(n / 2);
		return (n%2 == 1) ? b*b*val : b*b;
	}
};
using mll = Modll<MOD>;



void solve()
{
	ll N;
	cin >> N;
	auto s = cinv(N);

	ll maxSum = 0;

	REPS(C, 1, (N-2)/2){
		ll sum = 0;
		for (ll n=1; ; n++){
			ll A = N-1-n*C;
			if (A <= C) break;
			if ((N-1)%C == 0){
				if (n*C >= N/2) break;
			}

			sum += s[n*C] + s[N-1-n*C];
			chmax(maxSum, sum);
		}
	}

	cout << maxSum << '\n';
}

int main(){
	solve();
	return 0;
}
