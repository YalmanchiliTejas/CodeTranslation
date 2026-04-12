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
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;

const double PI=3.14159265358979323846;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REP1(i, n) for(int i = 1; i <= (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define LEN(x) ((int)(x).length())
#define ZERO(a) memset(a, 0, sizeof(a))

#define RAD(d) (PI * (d) / 180)
#define DEG(r) (180.0 * (r) / PI)

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

template<class T> T accumulate(const vector<T> &v)
{
	T sum = 0;
	REP(i, SZ(v)){ sum += v[i]; }
	return sum;
}

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

string &to_upper(string &s)
{
	REP(i, s.length()){
		if('a' <= s[i] && s[i] <= 'z'){
			s[i] -= 32;
		}
	}

	return s;
}

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
	string S;
	cin >> S;

	if(S[0] == S[1] && S[1] == S[2])
		cout << "No" << endl;
	else
	{
		cout << "Yes" << endl;
	}
	


	return 0;
}
