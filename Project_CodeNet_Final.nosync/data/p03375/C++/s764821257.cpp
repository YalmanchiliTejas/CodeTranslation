#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i = 0; i < (n); i++)
#define repr(i,b,e) for(int i = (b); i <= (e); i++)

#define pr(x) do{cerr << (#x) << " = " << (x) << endl;}while(0)
#define pri(x,i) do{cerr << (#x) << "[" << i << "] = " << (x[i]) << endl;}while(0)
#define UNIQUE(v) do{ (v).erase( unique(begin(v), end(v)), end(v) ); } while(0)

namespace std {
	template<class S, class T> pair<S, T> operator + (const pair<S, T> &a, const pair<S, T> &b) {return mp<S, T>(a.first + b.first, a.second + b.second);}
	template<class S, class T> pair<S, T> operator - (const pair<S, T> &a, const pair<S, T> &b) {return mp<S, T>(a.first - b.first, a.second - b.second);}
	template<class S, class T> pair<S, T>& operator += (pair<S, T> &a, const pair<S, T> &other) {return a = a + other;}
	template<class S, class T> pair<S, T>& operator -= (pair<S, T> &a, const pair<S, T> &other) {return a = a - other;}
	template<class S, class T> ostream& operator << (ostream& ost, pair<S, T> p) {ost << "(" << p.first << ", " << p.second << ")";return ost;}
	template<class T> ostream& print_iterable_container(ostream& ost, T& container) {
		for (auto&& iter = begin(container); iter != end(container); ++iter) ost << (iter == begin(container) ? " [ " : ", ") << (*iter);
		return ost << " ]";
	}
#	define APPLY_PRINT_ITERABLE_CONTAINER(container_type)\
	template<class T> ostream& operator << (ostream& ost, container_type<T>& container) {\
		return print_iterable_container(ost, container);\
	}
	APPLY_PRINT_ITERABLE_CONTAINER(vector);
	APPLY_PRINT_ITERABLE_CONTAINER(list);
	APPLY_PRINT_ITERABLE_CONTAINER(deque);
}

template<class T> inline bool CHMAX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool CHMIN(T &l,const T &r){return l>r?l=r,1:0;}

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

using ld = long double;

template<class T> using VV = vector<vector<T> >;
template<class T> using maxPQ = priority_queue<T>;
template<class T> using minPQ = priority_queue<T, vector<T>, greater<T> >;
template<class T, class U> using uomap = unordered_map<T, U>;
template<class T> using uoset = unordered_set<T>;

const ll INF = 1001001001;
const ll INFll = (ll)INF * INF;
// const ll MOD = 1000000007;
// const ll MOD_FFT = 998244353;
const ld EPS = 1e-15;

//function<void(int,int)> tensi_no_3p=[&](int v,int d){
//};

// mod STARTS HERE

namespace mod {
	struct Mod {
		ll M;
		Mod(ll M) : M(M) {}

		// a ** n % M
		ll pow(ll a, ll n) {
			ll ret = 1 % M;
			while (n > 0) {
				if (n & 1) ret = ret * a % M;
				a = a * a % M;
				n /= 2;
			}
			return ret;
		}

		ll inv_fermat(ll a) {
			return pow(a, M - 2);
		}

		// inverse using ext-gcd (initially copied from iwi-san)
		inline ll inv(ll a) {
			ll b = M, u = 1, v = 0;
			while (b) {
				ll t = a / b;
				swap(a -= t * b, b);
				swap(u -= t * v, v);
			}
			return (u % M + M) % M;
		}

		// [inv(i) for i in range(n + 1)]
		vll invs(int n) {
			assert(n >= 1);
			vll ret(n + 1);
			ret[1] = 1;
			for (int i = 2; i <= n; i++) {
				ret[i] = M - ret[M % i] * (M / i) % M;
			}
			return move(ret);
		}

		// [pow(a, n) for a in range(n + 1)]
		vll powers(ll a, int n) {
			assert(n >= 0);
			vll ret(n + 1);
			ret[0] = 1 % M;
			for (int i = 1; i <= n; i++) {
				ret[i] = ret[i - 1] * a % M;
			}
			return move(ret);
		}

		// [i! for i in range(n + 1)]
		vll facts(int n) {
			assert(n >= 0);
			vll ret(n + 1);
			ret[0] = 1 % M;
			for (int i = 1; i <= n; i++) {
				ret[i] = ret[i - 1] * i % M;
			}
			return move(ret);
		}

		// [nCr for r in range(n + 1)]
		vll combs(int n) {
			assert(n >= 0);
			vll ret(n + 1);
			ret[0] = 1 % M;
			for (int i = 1; i <= n; i++) {
				ret[i] = ret[i - 1] * (n + 1 - i) % M * inv(i) % M;
			}
			return move(ret);
		}
	};
}

// mod ENDS HERE

int main() {
	ios_base::sync_with_stdio(false);
	ll N, M; cin >> N >> M;
	mod::Mod md(M);
	vll combN = md.combs(N);
	vll pow2s = md.powers(2, 10000000);  // 2 ** i
	vll powpow2s(pow2s.size());  // (2 ** (2 ** i))
	powpow2s[0] = 2;
	repr(i, 1, powpow2s.size() - 1) powpow2s[i] = powpow2s[i - 1] * powpow2s[i - 1] % M;
	vvll ways2(N + 1, vll(N + 1));
	rep(i, N + 1) ways2[0][i] = 0;
	rep(i, N + 1) ways2[i][0] = 1;
	repr(i, 1, N) repr(j, 1, i) ways2[i][j] = ((1 + j) * ways2[i - 1][j] + ways2[i - 1][j - 1]) % M;
	vll ways(N + 1);
	rep(i, N + 1) {
		ll hoge = 0;
		rep(j, i + 1) {
			ll tmp = ways2[i][j];
			tmp = tmp * pow2s[(N - i) * j] % M;
			tmp = tmp * powpow2s[N - i] % M;
			hoge = (hoge + tmp) % M;
		}
		ways[i] = hoge;
	}
	ll ans = 0;
	rep(i, N + 1) {
		if (i % 2 == 0) {
			ans = (ans + combN[i] * ways[i]) % M;
		}
		else {
			ll minus = combN[i] * ways[i] % M;
			ans = (ans - minus + M) % M;
		}
	}
	// pr(ways);
	// pr(ways2);
	cout << ans % M << endl;
	return 0;
}
