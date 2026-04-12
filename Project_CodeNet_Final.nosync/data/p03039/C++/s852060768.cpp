#include "bits/stdc++.h"
using namespace std;
///////////////////////////////////////////
const long long int INF = 1LL<<60;
const long long int Mod = 1000000007;
using ll = long long int; using ci = const int;
using vi = vector<int>;  using Vi = vector<long long int>;
using P = pair<int, int>;  using PLL = pair<ll, ll>;
using matrix = vector<vector<ll>>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rep(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
#define p_queue(v) priority_queue<v, vector<v>, greater<v> >
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////

template<int MOD> struct Fp {
	long long val;
	constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
		if (val < 0) v += MOD;
	}
	constexpr int getmod() { return MOD; }
	constexpr Fp operator - () const noexcept {
		return val ? MOD - val : 0;
	}
	constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
	constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
	constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
	constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
	constexpr Fp& operator += (const Fp& r) noexcept {
		val += r.val;
		if (val >= MOD) val -= MOD;
		return *this;
	}
	constexpr Fp& operator -= (const Fp& r) noexcept {
		val -= r.val;
		if (val < 0) val += MOD;
		return *this;
	}
	constexpr Fp& operator *= (const Fp& r) noexcept {
		val = val * r.val % MOD;
		return *this;
	}
	constexpr Fp& operator /= (const Fp& r) noexcept {
		long long a = r.val, b = MOD, u = 1, v = 0;
		while (b) {
			long long t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		val = val * u % MOD;
		if (val < 0) val += MOD;
		return *this;
	}
	constexpr bool operator == (const Fp& r) const noexcept {
		return this->val == r.val;
	}
	constexpr bool operator != (const Fp& r) const noexcept {
		return this->val != r.val;
	}
	friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
		return os << x.val;
	}
	friend constexpr istream& operator >> (istream &is, Fp<MOD>& x) noexcept {
		return is >> x.val;
	}
	friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
		if (n == 0) return 1;
		auto t = modpow(a, n / 2);
		t = t * t;
		if (n & 1) t = t * a;
		return t;
	}
};

const ll MOD = Mod;
using mint = Fp<MOD>;

const ll MAX = 5000001;//10^7が限界
//const ll MOD = INT64_MAX;
ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (ll i = 2; i < MAX; i++){
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
ll COM(ll n, ll k){
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

typedef mint RUI;//型は適当に合わせて.
RUI rui(ll num,ll k){//num^k
	RUI ans = 1;
	RUI n = num;
	while(k>0){
		if(k&1)ans *= n;
		n *= n;
		k /= 2;
	}
	return ans;
}


ll n,m,k;

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	std::cout<<std::fixed<<std::setprecision(30);
	cin>>n>>m>>k;
	COMinit();
	mint ans = 0;
	rep(i,n){//xj-xi = i
		if(i==0){
			//yi!=yj
		}else{
			mint tmp = (n - i)*m*m;
			tmp *= COM(n*m-2,k-2);
			tmp *= i;
			ans += tmp;
		}
	}
	rep(i,m){
		if(i==0){

		}else{
			mint tmp = (m-i)*n*n;
			tmp *= COM(n*m-2,k-2);
			tmp *= i;
			ans += tmp;
		}
	}
	print(ans);
	return 0;
}