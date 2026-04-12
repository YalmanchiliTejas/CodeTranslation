#ifndef __INTMOD_H__0001__
#define __INTMOD_H__0001__

#include <vector>
#include <iostream>
#include <cassert>
#include <iostream>

/* Modulus must be less than 0x80000000, and must not be 0. */
template <uint32_t Modulus>
class IntMod {
	typedef int Int;
	typedef unsigned int UInt;
	typedef long long Long;
	typedef unsigned long long ULong;

public:
	template <uint32_t Modulus_>
	friend bool operator==(const IntMod<Modulus_>& left, const IntMod<Modulus_>& right);
	template <uint32_t Modulus_>
	friend bool operator!=(const IntMod<Modulus_>& left, const IntMod<Modulus_>& right);
	template <uint32_t Modulus_>
	friend bool operator<(const IntMod<Modulus_>& left, const IntMod<Modulus_>& right);
	template <uint32_t Modulus_>
	friend bool operator<=(const IntMod<Modulus_>& left, const IntMod<Modulus_>& right);
	template <uint32_t Modulus_>
	friend bool operator>(const IntMod<Modulus_>& left, const IntMod<Modulus_>& right);
	template <uint32_t Modulus_>
	friend bool operator>=(const IntMod<Modulus_>& left, const IntMod<Modulus_>& right);

private:
	UInt value_m;

public:
	IntMod() { value_m = 0; }
	IntMod(UInt value) { value_m = value % Modulus; }
	IntMod(ULong value) { value_m = value % Modulus; }
	IntMod(Int value) {
		Int tmp = value % (Int)Modulus;
		value_m = tmp >= 0 ? tmp : Modulus - (unsigned int)(-tmp);
	}
	IntMod(Long value) {
		Int tmp = value % (Long)Modulus;
		value_m = tmp >= 0 ? tmp : Modulus - (unsigned int)(-tmp);
	}
	IntMod(const IntMod& other) : value_m(other.value_m) {}
	IntMod& operator=(const IntMod& other) { value_m = other.value_m; return *this; }
	
	const IntMod& operator+() const { return *this; }
	IntMod operator-() const { return IntMod(Modulus - value_m); }
	IntMod& operator++() {
		++value_m;
		if (value_m == Modulus) value_m = 0;
		return *this;
	}
	IntMod& operator--() {
		if (value_m == 0) value_m = Modulus;
		--value_m;
		return *this;
	}
	IntMod operator++(int dummy) {
		IntMod tmp(*this);
		++(*this);
		return tmp;
	}
	IntMod operator--(int dummy) {
		IntMod tmp(*this);
		--(*this);
		return tmp;
	}
	IntMod& operator+=(const IntMod& right) {
		value_m += right.value_m;		// value_m < 0x80000000
		if (value_m >= Modulus) value_m -= Modulus;
		return *this;
	}
	IntMod& operator-=(const IntMod& right) {
		if (value_m < right.value_m) value_m += Modulus;
		value_m -= right.value_m;
		return *this;
	}
	IntMod& operator*=(const IntMod& right) {
		value_m = ((ULong)value_m * right.value_m) % Modulus;
		return *this;
	}	
	IntMod& operator/=(const IntMod& right) {
		(*this) *= (right.Inverse());
		return *this;
	}
	// for power
	IntMod operator[](ULong exp) const {
		return Pow(exp);
	}

	/* Modulus must be a prime. */
	IntMod Inverse() const { return (*this).Pow(Modulus - 2); }
	IntMod Pow(ULong exp) const {
		IntMod product = 1;
		IntMod factor(*this);
		while (exp > 0) {
			if (exp & 1) product *= factor;
			factor *= factor;
			exp >>= 1;
		}
		return product;
	}
	UInt Get_value() const {
		return value_m;
	}

	static IntMod Fact(UInt num) {
		static std::vector<IntMod> table(1, 1);
		if (table.size() > num) return table[num];

		int old_size = table.size();
		table.resize(num + 1);
		for (int i = old_size; i <= num; i++) {
			table[i] = table[i - 1] * i;
		}
		return table[num];
	}

	static IntMod Combi(UInt n, UInt r) {
		if (n < r) throw "okashii";
		return IntMod::Fact(n) / (IntMod::Fact(n - r) * IntMod::Fact(r));
	}

	static std::vector<IntMod> Inverse_list(int size) {
		assert(size < Modulus);
		std::vector<IntMod> ret_arr(size + 1);
		ret_arr[1] = 1;
		for (int i = 2; i <= size; ++i) {
			ret_arr[i] = ((ULong)(Modulus - Modulus / i) * ret_arr[Modulus % i].Get_value()) % Modulus;
		}
		return ret_arr;
	}
};

template <uint32_t Modulus>
IntMod<Modulus> operator+(const IntMod<Modulus>& left, const IntMod<Modulus>& right) {
	IntMod<Modulus> ret(left);
	ret += right;
	return ret;
}

template <uint32_t Modulus>
IntMod<Modulus> operator-(const IntMod<Modulus>& left, const IntMod<Modulus>& right) {
	IntMod<Modulus> ret(left);
	ret -= right;
	return ret;
}

template <uint32_t Modulus>
IntMod<Modulus> operator*(const IntMod<Modulus>& left, const IntMod<Modulus>& right) {
	IntMod<Modulus> ret(left);
	ret *= right;
	return ret;
}

template <uint32_t Modulus>
IntMod<Modulus> operator/(const IntMod<Modulus>& left, const IntMod<Modulus>& right) {
	IntMod<Modulus> ret(left);
	ret /= right;
	return ret;
}


template <uint32_t Modulus>
bool operator==(const IntMod<Modulus>& left, const IntMod<Modulus>& right) { return left.value_m == right.value_m; }
template <uint32_t Modulus>
bool operator!=(const IntMod<Modulus>& left, const IntMod<Modulus>& right) { return left.value_m != right.value_m; }
/* for set/map */
template <uint32_t Modulus>
bool operator<(const IntMod<Modulus>& left, const IntMod<Modulus>& right) { return left.value_m < right.value_m; }
template <uint32_t Modulus>
bool operator<=(const IntMod<Modulus>& left, const IntMod<Modulus>& right) { return left.value_m <= right.value_m; }
template <uint32_t Modulus>
bool operator>(const IntMod<Modulus>& left, const IntMod<Modulus>& right) { return left.value_m > right.value_m; }
template <uint32_t Modulus>
bool operator>=(const IntMod<Modulus>& left, const IntMod<Modulus>& right) { return left.value_m >= right.value_m; }

template <uint32_t Modulus, class Integer>
IntMod<Modulus> operator+(const IntMod<Modulus>& left, Integer right) { return left + IntMod<Modulus>(right); }
template <uint32_t Modulus, class Integer>
IntMod<Modulus> operator+(Integer left, const IntMod<Modulus>& right) { return IntMod<Modulus>(left) + right; }
template <uint32_t Modulus, class Integer>
IntMod<Modulus> operator-(const IntMod<Modulus>& left, Integer right) { return left - IntMod<Modulus>(right); }
template <uint32_t Modulus, class Integer>
IntMod<Modulus> operator-(Integer left, const IntMod<Modulus>& right) { return IntMod<Modulus>(left) - right; }
template <uint32_t Modulus, class Integer>
IntMod<Modulus> operator*(const IntMod<Modulus>& left, Integer right) { return left * IntMod<Modulus>(right); }
template <uint32_t Modulus, class Integer>
IntMod<Modulus> operator*(Integer left, const IntMod<Modulus>& right) { return IntMod<Modulus>(left) * right; }
template <uint32_t Modulus, class Integer>
IntMod<Modulus> operator/(const IntMod<Modulus>& left, Integer right) { return left / IntMod<Modulus>(right); }
template <uint32_t Modulus, class Integer>
IntMod<Modulus> operator/(Integer left, const IntMod<Modulus>& right) { return IntMod<Modulus>(left) / right; }

template <uint32_t Modulus>
std::istream& operator<<(std::istream& ist, const IntMod<Modulus>& val) {
	uint64_t tmp;
	ist >> tmp;
	val = tmp;
	return ist;
}

template <uint32_t Modulus>
std::ostream& operator<<(std::ostream& ost, const IntMod<Modulus>& val) {
	ost << val.Get_value();
	return ost;
}

typedef IntMod<1000000007> MInt;

#if 1
MInt operator"" _m(unsigned long long num) { return MInt(num); }
#endif

#endif
#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
#include <functional>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <limits>
#include <numeric>
#include <valarray>
#include <fstream>

using namespace std;
typedef unsigned int uint;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL, LL> PP;
#define REP(i, a, n) for(LL i = (a), i##_max = (n); i < i##_max; ++i)
#define REM(i, a, n) for(LL i = (LL)(n) - 1, i##min = (a); i >= i##min; --i)
#define ALL(arr) (arr).begin(), (arr).end()
#define FLOAT fixed << setprecision(16)
#define SPEEDUP {cin.tie(NULL); ios::sync_with_stdio(false);}
const int INF = 0x3FFFFFFF;
const LL INFLL = 0x3FFFFFFF3FFFFFFF;
const double INFD = 1.0e+308;
const string INFSTR = "\x7f";
const double EPS = 1.0e-9;

void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
template <class T, class U>
istream& operator>>(istream& ist, pair<T, U>& right) { return ist >> right.first >> right.second; }
template <class T, class U>
ostream& operator<<(ostream& ost, const pair<T, U>& right) { return ost << right.first << ' ' << right.second; }
template <class T, class TCompatible, size_t N>
void Fill(T(&dest)[N], const TCompatible& val) { fill(dest, dest + N, val); }
template <class T, class TCompatible, size_t M, size_t N>
void Fill(T(&dest)[M][N], const TCompatible& val) { for (int i = 0; i < M; ++i) Fill(dest[i], val); }
template<class T>
T Compare(T left, T right) { return left > right ? 1 : (left < right ? -1 : 0); }
istream& Ignore(istream& ist) { string s; ist >> s; return ist; }
bool Inside(int i, int j, int h, int w) { return i >= 0 && i < h && j >= 0 && j < w; }
template <class T>
T Next() { T buf; cin >> buf; return buf; }

#ifdef ONLY_MY_ENVIR
#include "IntMod.h"
#include "UnionFind.h"
#include "Graph.h"
#include "Range.h"
#include "Global.h"
#include "FlowSolver.h"
#include "Tree.h"
#include "SuffixArray.h"
#include "Geometry.h"
#include "Matrix.h"
#include "SegmentTree.h"
#include "SegmentTree2D.h"
#include "BIT.h"
#include "Rational.h"
#include "Position.h"
#include "Factorization.h"
#include "Math.h"
#endif

#ifdef __GNUC__
typedef __int128 LLL;
istream& operator>> (istream& ist, __int128& val) { LL tmp;  ist >> tmp; val = tmp; return ist; }
ostream& operator<< (ostream& ost, __int128 val) { LL tmp = val; ost << tmp; return ost; }
#endif

#if 1234567891
#include <array>
#include <random>
#include <unordered_set>
#include <unordered_map>
template<typename T>
using PriorityQ = priority_queue<T, vector<T>, greater<T> >;
// template <class T>
// auto Is(const T& value) { return [value](const auto& comparand) -> bool { return comparand == value; }; }
#endif


string s;
int K;
MInt DP[10001][100];
int main() {
	cin >> s >> K;

	int curr = 0;
	REP(i, 0, s.size()) {
		REP(k, 0, K) {
			REP(dk, 0, 10) {
				DP[i + 1][(k + dk) % K] += DP[i][k];
			}
		}
		REP(dk, 0, s[i] - '0') {
			++DP[i + 1][(curr + dk) % K];
		}
		curr += s[i] - '0';
		curr %= K;
	}
	cout << DP[s.size()][0] - 1 + (curr == 0) << endl;

	return 0;
}

