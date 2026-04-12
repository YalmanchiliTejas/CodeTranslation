#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <bitset>
#include <cstdint>
#include <climits>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef vector<ll> VL;
typedef vector<vector<ll>> VVL;
typedef vector<double> VD;
typedef vector<vector<double>> VVD;

const double PI=3.14159265358979323846;
const int IINF = 1 << 30;
const ll LINF = 1LL << 62;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REP1(i, n) for(int i = 1; i <= (int)(n); i++)
#define REPLL(i, n) for(ll i = 0; i < (ll)(n); i++)
#define REPLL1(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define LEN(x) ((int)(x).length())
#define ZERO(a) memset(a, 0, sizeof(a))
#define RAD(d) (PI * (d) / 180)
#define DEG(r) (180.0 * (r) / PI)
#define POPCOUNT(x) __builtin_popcount(x)

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

template<class T> void dump(const vector<T> &v)
{
	REP(i, SZ(v)-1){ cout << v[i] << " "; }
	cout << v[SZ(v)-1] << endl;
}

template<class T> void dump(int w, int h, const vector<T> &v)
{
	REP(j, h){
		REP(i, w-1){ cout << v[j * w + i] << " "; }
		cout << v[j * w + w-1] << endl;
	}
}

// 和
template<class T> T accumulate(const vector<T> &v)
{
	T sum = 0;
	REP(i, SZ(v)){ sum += v[i]; }
	return sum;
}

// 和（範囲指定）
template<class T> T accumulate(const vector<T> &v, int start, int length)
{
	T sum = 0;
	REP(i, length){
		sum += v[start + i];
	}
	return sum;
}

// 平均
template<class T> T average(const vector<T> &v)
{
	return accumulate(v) / SZ(v);
}

// 行列
template<class T> struct Matrix
{
	T w, h;
	vector<T> A;
	Matrix(T w_, T h_) : w(w_), h(h_), A(w * h) {}
	T get(T x, T y) const { return A[y * w + x]; }
};

template<class T> void input(Matrix<T> &m)
{
	REP(j, m.h){
		REP(i, m.w){
			cin >> m.A[j * m.w + i];
		}
	}
}

template<class T> Matrix<T> prod(const Matrix<T> &a, const Matrix<T> &b)
{
	Matrix<T> m(b.w, a.h);

	REP(j, m.h){
		REP(i, m.w){
			ll c = 0;
			REP(k, a.w){
				c += a.A[j * a.w + k] * b.A[k * b.w + i];
			}
			m.A[j * m.w + i] = c;
		}
	}

	return m;
}

void dump(const Matrix<ll> &m)
{
	REP(j, m.h){
		REP(i, m.w-1){ printf("%lld ", m.A[j * m.w + i]); }
		printf("%lld\n", m.A[j * m.w + m.w-1]);
	}
}

void dump(const Matrix<double> &m)
{
	REP(j, m.h){
		REP(i, m.w-1){ printf("%f ", m.A[j * m.w + i]); }
		printf("%f\n", m.A[j * m.w + m.w-1]);
	}
}

// 文字列の大文字化
string &to_upper(string &s)
{
	REP(i, s.length()){
		if('a' <= s[i] && s[i] <= 'z'){
			s[i] -= 32;
		}
	}

	return s;
}

// 文字列の小文字化
string &to_lower(string &s)
{
	REP(i, s.length()){
		if('A' <= s[i] && s[i] <= 'Z'){
			s[i] += 32;
		}
	}

	return s;
}

// すべての約数を列挙する
template <class T> vector<T> get_divisors(T n)
{
	vector<T> ret;
	for(T i = 1; i * i <= n; i++){
		if(n % i == 0){
			ret.push_back(i);
			if(i * i != n)
				ret.push_back(n / i);
		}
	}
	sort(ALL(ret));
	return ret;
}

// 1-sqrt(N)までの約数を列挙する
template <class T> vector<T> get_divisors2(T n)
{
	vector<T> ret;
	for(T i = 1; i * i <= n; i++){
		if(n % i == 0){
			ret.push_back(i);
		}
	}
	return ret;
}

// 最大公約数(※ユークリッドの互除法)
template <class T> T gcd(T a, T b)
{
	if(a < b)
		return gcd(b, a);

	ll r;
	while((r = a % b)){
		a = b;
		b = r;
	}
	return b;
}

// ３数の最大公約数(※ユークリッドの互除法)
template <class T> T gcd(T a, T b, T c)
{
	return gcd(gcd(a, b), c);
}

// ３数以上の最大公約数
template <class T> T gcd(const vector<T> v)
{
	if(SZ(v) == 0)
		return 0;

	if(SZ(v) == 1)
		return v[0];

	if(SZ(v) == 2)
		return gcd(v[0], v[1]);

	T g = v[0];
	for(int i = 1; i < SZ(v); i++){
		g = gcd(g, v[i]);
	}
	return g;
}

// MOD計算
// 
// modint 構造体を使ってみませんか？ (C++) - noshi91のメモ
// https://noshi91.hatenablog.com/entry/2019/03/31/174006
// 
// 使い方:
//   const int MOD = 1000000007;
//   using mint = modint<MOD>;
//   mint a = 1234;
// 
template <std::uint_fast64_t Modulus> class modint {
	using u64 = std::uint_fast64_t;

public:
	u64 a;

	constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
	constexpr u64 &value() noexcept { return a; }
	constexpr const u64 &value() const noexcept { return a; }
	constexpr modint operator+(const modint rhs) const noexcept { return modint(*this) += rhs; }
	constexpr modint operator-(const modint rhs) const noexcept { return modint(*this) -= rhs; }
	constexpr modint operator*(const modint rhs) const noexcept { return modint(*this) *= rhs; }
	constexpr modint operator/(const modint rhs) const noexcept { return modint(*this) /= rhs; }
	constexpr modint &operator+=(const modint rhs) noexcept {
		a += rhs.a;
		if (a >= Modulus) {
			a -= Modulus;
		}
		return *this;
	}
	constexpr modint &operator-=(const modint rhs) noexcept {
		if (a < rhs.a) {
			a += Modulus;
		}
		a -= rhs.a;
		return *this;
	}
	constexpr modint &operator*=(const modint rhs) noexcept {
		a = a * rhs.a % Modulus;
		return *this;
	}
	constexpr modint &operator/=(modint rhs) noexcept {
		u64 exp = Modulus - 2;
		while (exp) {
			if (exp % 2) {
				*this *= rhs;
			}
			rhs *= rhs;
			exp /= 2;
		}
		return *this;
	}
};

int main()
{
	int N, M;
	cin >> N >> M;

	vector<set<int>> G(N);

	REP(i, M){
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].insert(b);
		G[b].insert(a);
	}

	VI V(N);
	REP(i, N){ V[i] = i; }

	int ans = 0;

	do{
		bool reached = true;
		REP(i, N-1){
			if(G[V[i]].find(V[i+1]) == G[V[i]].end()){
				reached = false;
				break;
			}
		}
		if(reached)
			ans++;
	}while(next_permutation(next(V.begin()), V.end()));

	cout << ans << endl;

	return 0;
}
