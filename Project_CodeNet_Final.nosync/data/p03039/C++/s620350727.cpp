#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64)1e18
#define INF (int32)1e9
#define REP(i, n) for(int64 i = 0;i < (n);i++)
#define FOR(i, a, b) for(int64 i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second

using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value!=0>::type
fill_v(U &u,const V... v){u=U(v...);}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value==0>::type
fill_v(U &u,const V... v){
  for(auto &e:u) fill_v<T>(e,v...);
}

bool in(string s1, string s2) {
  int64 idx = 0;
  REP(i, s2.size()) {
    if (idx < s1.size() && s1[idx] == s2[i]) idx++;
  }
  return idx == s1.size();
}

::std::vector<::std::int64_t> divisors(::std::int64_t x) {
	::std::vector<::std::int64_t> res;
	for (::std::int64_t i = 1; i*i <= x; ++i) {
		if (x % i == 0) {
			res.push_back(i);
			if (i * i != x) res.push_back(x / i);
		}
	}
	::std::sort(res.begin(), res.end());
	return res;
}

template<::std::uint_fast64_t mod>
class ModInt{
private:
	using value_type = ::std::uint_fast64_t;
	value_type n;
public:
	ModInt() : n(0) {}
	ModInt(value_type n_) : n(n_ % mod) {}
	ModInt(const ModInt& m) : n(m.n) {}

	template<typename T>
	explicit operator T() const { return static_cast<T>(n); }
	value_type get() const { return n; }

	friend ::std::ostream& operator<<(::std::ostream &os, const ModInt<mod> &a) {
		return os << a.n;
	}

	friend ::std::istream& operator>>(::std::istream &is, ModInt<mod> &a) {
		value_type x;
		is >> x;
		a = ModInt<mod>(x);
		return is;
	}

	bool operator==(const ModInt& m) const { return n == m.n; }
	bool operator!=(const ModInt& m) const { return n != m.n; }
	ModInt& operator*=(const ModInt& m){ n = n * m.n % mod; return *this; }

	ModInt pow(value_type b) const{
		ModInt ans = 1, m = ModInt(*this);
		while(b){
			if(b & 1) ans *= m;
			m *= m;
			b >>= 1;
		}
		return ans;
	}

	ModInt inv() const { return (*this).pow(mod-2); }
	ModInt& operator+=(const ModInt& m){ n += m.n; n = (n < mod ? n : n - mod); return *this; }
	ModInt& operator-=(const ModInt& m){ n += mod - m.n; n = (n < mod ? n : n - mod); return *this; }
	ModInt& operator/=(const ModInt& m){ *this *= m.inv(); return *this; }
	ModInt operator+(const ModInt& m) const { return ModInt(*this) += m; }
	ModInt operator-(const ModInt& m) const { return ModInt(*this) -= m; }
	ModInt operator*(const ModInt& m) const { return ModInt(*this) *= m; }
	ModInt operator/(const ModInt& m) const { return ModInt(*this) /= m; }
	ModInt& operator++(){ n += 1; return *this; }
	ModInt& operator--(){ n -= 1; return *this; }
	ModInt operator++(int){
		ModInt old(n);
		n += 1;
		return old;
	}
	ModInt operator--(int){
		ModInt old(n);
		n -= 1;
		return old;
	}
	ModInt operator-() const { return ModInt(mod-n); }
};

template<::std::size_t size, ::std::uint_fast64_t mod=1000000007>
class Factorial{
private:
	using value_type = ModInt<mod>;
	::std::vector<value_type> fact, inv;
public:
	Factorial() : fact(size+1, 1), inv(size+1, 1){
		for(::std::size_t i = 1; i <= size; ++i){
			fact[i] = fact[i-1] * value_type(i);
			inv[i] = fact[i].inv();
		}
	}

	value_type comb(::std::int64_t a, ::std::int64_t b){
		assert(a >= b);
		assert(b >= 0);
		return fact[a]*inv[b]*inv[a-b];
	}

	value_type& operator[](::std::size_t k){ return fact[k]; }
};

const int64 mod = 1e9+7;
using Mint = ModInt<mod>;
Factorial<412345> f;

int main(void) {
  int64 N, M, K;
  cin >> N >> M >> K;
  Mint res = 0;
  Mint sum = 0;
  REP(i, N) { sum += i-0; }
  REP(i, N) {
    res += sum * M * M * f.comb(N*M-2, K-2);
    sum -= N-i-1;
  }
  sum = 0;
  REP(i, M) { sum += i-0; }
  REP(i, M) {
    res += sum * N * N * f.comb(N*M-2, K-2);
    sum -= M-i-1;
  }
  cout << res << endl;

}