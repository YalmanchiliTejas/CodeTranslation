#include "bits/stdc++.h"
using namespace std;
#define Rep(i,n) for(int i=0;i<(int)(n);i++)
#define For(i,n1,n2) for(int i=(int)(n1);i<(int)(n2);i++)
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define RREP(i,n) for(ll i=((ll)(n)-1);i>=0;i--)
#define FOR(i,n1,n2) for(ll i=(ll)(n1);i<(ll)(n2);i++)
#define RFOR(i,n1,n2) for(ll i=((ll)(n1)-1);i>=(ll)(n2);i--)
#define all(a)  (a).begin(),(a).end()
#define SORT(a) sort((a).begin(),(a).end())
#define oorret 0
#define oor(x) [&](){try{x;} catch(const out_of_range& oor){return oorret;} return x;}()
#define IOS cin.tie(0),ios::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
template<typename T1, typename T2> inline bool chmin(T1& a, T2 b) { if (a > b) { a = b; return 1; }return 0; }
template<typename T1, typename T2> inline bool chmax(T1& a, T2 b) { if (a < b) { a = b; return 1; }return 0; }
template<class Type>struct is_vector : std::false_type {};
template<class ValueType, class Alloc>struct is_vector<std::vector<ValueType, Alloc>> : std::true_type {};
template <typename T> inline ostream& operator << (ostream& out, const vector<T>& v) {
	if (v.empty())return out;
	constexpr bool is_vector_v = is_vector<T>::value;
	if (is_vector_v)for (auto itr = v.begin(); itr != v.end();)out << (*itr), out << ((++itr != v.end()) ? "\n" : "");
	else for (auto itr = v.begin(); itr != v.end();)out << (*itr), out << ((++itr != v.end()) ? " " : "");
	return out;
}
inline void put() {}
template<class T> inline void put(const T& first) { std::cout << first << "\n"; }
template<class T, class... N> inline void put(const T& first, const N& ... rest) { std::cout << first << " "; put(rest...); }
inline void putn() {}
template<class T, class... N> inline void putn(const T& first, const N& ... rest) { std::cout << first << "\n"; putn(rest...); }

template<typename T, typename U>
inline T pow(T x, U exp) {
	if (exp <= 0) {
		return 1;
	}
	if (exp % 2 == 0) {
		T d = pow(x, exp / 2);
		return d * d;
	} else {
		return (x * pow(x, exp - 1));
	}
}

template<typename T>
inline T fact(int_fast32_t n) {
	static vector<T> table(1, 1);
	if (n >= (int)table.size()) {
		uint_fast32_t s = table.size();
		for (T i = s; i < n + 1; ++i) {
			table.push_back(table.back() * i);
		}
	}
	if (n < 0) return 1;
	else return table[n];
}

template<typename T>
inline T invfact(int_fast32_t n) {
	static vector<T> invtable(1, 1);
	if (n >= (int)invtable.size()) {
		uint_fast32_t s = invtable.size();
		for (T i = s; i < n + 1; ++i) {
			invtable.push_back(invtable.back() / i);
		}
	}
	if (n < 0) return 1;
	else return invtable[n];
}

template<typename T>
inline T comb(uint_fast32_t n, uint_fast32_t m, bool closed = true) {//nCm
	if (n < m)return 0;
	else if (closed)return fact<T>(n) * invfact<T>(m) * invfact<T>(n - m);
	else fact<T>(n) / fact<T>(m) / fact<T>(n - m);
}

template<uint_fast64_t Mod>
class ModInt {
	using lint = int_fast64_t;
public:
	lint a;
	ModInt(lint val = 0) { if (val >= Mod) { val %= Mod; }a = val; }
	ModInt operator-() { return ModInt(Mod - a); }//単項-演算子(-a)のオーバーロード
	ModInt operator=(const ModInt n) { a = n.a; return a; }
	ModInt operator+(const ModInt n) { if ((a + n.a) >= Mod) { return a + n.a - Mod; } else { return a + n.a; } }
	ModInt operator-(const ModInt n) { return a + (Mod - n.a); }
	ModInt operator*(const ModInt n) { return a * n.a; }
	ModInt operator/(const ModInt n) { return (*this) * pow(n, Mod - 2); }
	ModInt& operator+=(const ModInt n) { (*this) = (*this) + n; return *this; }
	ModInt& operator-=(const ModInt n) { (*this) = (*this) + (Mod - n.a); return *this; }
	ModInt& operator*=(const ModInt n) { (*this) = (*this) * n; return *this; }
	ModInt& operator/=(const ModInt n) { (*this) = (*this) / n; return *this; }
	ModInt& operator++(int) { (*this) = (*this) + 1; return *this; }//前置インクリメントs(++a)のオーバーロード
	ModInt& operator++() { (*this) = (*this) + 1; return *this; }//後置インクリメント(a++)のオーバーロード
	ModInt& operator--(int) { (*this) = (*this) + (Mod - 1); return *this; }//前置デクリメント(--a)のオーバーロード
	ModInt& operator--() { (*this) = (*this) + (Mod - 1); return *this; }//後置デクリメント(a--)のオーバーロード
	ModInt inv() { ModInt temp(1); return temp / (*this); }//逆数を返す関数 return (*this)/(*this)/(*this);でもいい
	bool operator<(const ModInt n) { return a < n.a; }
	bool operator<=(const ModInt n) { return a <= n.a; }
	bool operator>(const ModInt n) { return a > n.a; }
	bool operator>=(const ModInt n) { return a >= n.a; }
	bool operator==(const ModInt n) { return a == n.a; }
	bool operator!=(const ModInt n) { return a != n.a; }
	//下の関係演算子はpow関数で要請される
	bool operator<(const int n) { return a < n; }
	bool operator<=(const int n) { return a <= n; }
	bool operator>(const int n) { return a > n; }
	bool operator>=(const int n) { return a >= n; }
	bool operator==(const int n) { return a == n; }
	ModInt operator%(const int n) { return a % n; }
};
template<uint_fast64_t Mod> inline
ostream& operator <<(ostream& o, const ModInt<Mod>& t) {
	o << t.a;
	return o;
}
template<uint_fast64_t Mod> inline
istream& operator >>(istream& i, ModInt<Mod>& t) {
	i >> t.a;
	return i;
}

constexpr uint_fast64_t mod = 1e9 + 7;
//constexpr uint_fast64_t mod = 998244353;
using mi = ModInt<mod>;

mi dp[10000][100][2] = {};

int main() {
	IOS;
	string s;
	int d;
	cin >> s >> d;
	int l = s.size();
	vector<int> n(l);
	REP(i, l) {
		n[i] = s[i] - '0';
	}
	dp[0][0][0] = 1;
	REP(i, l) {
		REP(j, d) {
			dp[i + 1][(j + n[i]) % d][0] += dp[i][j][0];
			REP(k, n[i]) {
				int t = (j + k) % d;
				dp[i + 1][t][1] += dp[i][j][0];
			}
			REP(k, 10) {
				dp[i + 1][(j + k) % d][1] += dp[i][j][1];
			}
		}
	}
	put(dp[l][0][0] + dp[l][0][1] - 1);
	return 0;
}
