#ifndef __INTMOD_H__0001__
#define __INTMOD_H__0001__

#include <vector>
#include <iostream>
#include <cassert>
#include <iostream>

template <unsigned int Modulus>
class IntMod {
	typedef unsigned long long ULL;
private:
	unsigned int value_m;

	void Copy(const IntMod& other) { value_m = other.value_m; }
	bool Modulus_is_valid() { return Modulus != 0; }
public:
	IntMod() { value_m = 0; }
	IntMod(unsigned int value) { value_m = value % Modulus; }
	IntMod(unsigned long long value) { value_m = value % Modulus; }
	IntMod(int value) { 
		if (Modulus >= 0x80000000UL) {
			value_m = value >= 0 ? (unsigned int)value % Modulus : Modulus - (unsigned int)(-value);
		} else {
			int tmp = value % (int)Modulus;
			value_m = tmp >= 0 ? tmp : Modulus - (unsigned int)(-tmp);
		}
	}
	IntMod(const IntMod& other) { Copy(other); }
	IntMod& operator=(const IntMod& other) { Copy(other); return *this; }
	bool operator==(const IntMod& right) const { return value_m == right.value_m; }
	bool operator!=(const IntMod& right) const { return value_m != right.value_m; }
	IntMod& operator++() {
		++value_m; 
		value_m %= Modulus;
		return *this;
	}
	IntMod& operator--() {
		if (value_m == 0) { value_m = Modulus - 1; }
		else { --value_m; }
		return *this;
	}
	IntMod operator-() const {
		if (value_m == 0) return IntMod(0);
		return IntMod(Modulus - value_m);
	}
	IntMod& operator+=(const IntMod& right) {
		ULL sum = (ULL)value_m + right.value_m;
		if (sum >= (ULL)Modulus) { value_m = (unsigned int)(sum - (ULL)Modulus); }
		else { value_m = (unsigned int)sum; }
		return *this;
	}
	IntMod& operator-=(const IntMod& right) {
		(*this) += (-right);
		return *this;
	}
	IntMod operator+(const IntMod& right) const {
		IntMod ret(*this);
		ret += right;
		return ret;
	}
	IntMod operator-(const IntMod& right) const {
		IntMod ret(*this);
		ret -= right;
		return ret;
	}
	IntMod& operator*=(const IntMod& right) {
		ULL tmp = (ULL)value_m * right.value_m;
		value_m = tmp % (ULL)Modulus;
		return *this;
	}	
	IntMod& operator/=(const IntMod& right) {
		(*this) *= (right.Inverse());
		return *this;
	}
	IntMod operator*(const IntMod& right) const {
		IntMod ret(*this);
		ret *= right;
		return ret;
	}
	IntMod operator/(const IntMod& right) const {
		IntMod ret(*this);
		ret /= right;
		return ret;
	}
	// for power
	IntMod operator[](unsigned int exp) const {
		return Pow(exp);
	}

	/* 素数判定は自分でしろ */
	IntMod Inverse() const {
		return (*this).Pow(Modulus - 2);
	}
	IntMod Pow(unsigned int exp) const {
		unsigned int arr[32];		// TODO
		ULL sum = 1;
		arr[0] = value_m;
		for (int i = 1; i < 32; ++i) {
			arr[i] = ((ULL)arr[i - 1] * arr[i - 1]) % (ULL)Modulus;
		}
		for (int i = 0; i < 32; ++i) {
			if (exp & (0x1 << i)) {
				sum *= arr[i]; sum %= (ULL)Modulus;
			}
		}
		return (unsigned int)sum;
	}
	IntMod Fact() const {
		static std::vector<IntMod> table;
		int factoriand = Get_value();
		if (table.size() > factoriand) {
			return table[factoriand];
		}

		int old_size = table.size();
		table.resize(factoriand + 1);
		for (int i = old_size; i <= factoriand; i++) {
			table[i] = (i == 0 ? 1 : table[i - 1] * i);
		}
		return table[factoriand];
	}
	IntMod Combination(const IntMod& right) const {
		if (value_m < right.value_m) throw "okashii";
		return Fact() / ((*this - right).Fact() * right.Fact());
	}
	unsigned int Get_value() const {
		return value_m;
	}
	static std::vector<IntMod> Inverse_list(int size) {
		assert(size < Modulus);
		std::vector<IntMod> ret_arr(size + 1);
		ret_arr[1] = 1;
		for (int i = 2; i <= size; ++i) {
			ret_arr[i] = ((ULL)(Modulus - Modulus / i) * ret_arr[Modulus % i].Get_value()) % Modulus;
		}
		return ret_arr;
	}
};
typedef IntMod<1000000007> MInt;

//template <unsigned int Modulus>
//IntMod<Modulus> operator*(const int left, const IntMod<Modulus>& right) {
//	IntMod<Modulus> ret(left);
//	ret *= right;
//	return ret;
//}
//template <unsigned int Modulus>
//IntMod<Modulus> operator/(const int left, const IntMod<Modulus>& right) {
//	IntMod<Modulus> ret(left);
//	ret /= right;
//	return ret;
//}

#if 1
MInt operator"" _m(unsigned long long num) { return MInt(num); }
#endif

template <unsigned int Modulus>
std::ostream& operator<<(std::ostream& ost, const IntMod<Modulus>& val) {
	ost << val.Get_value();
	return ost;
}


#endif
#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#define REP(i,a,n) for(LL i = (a); i < (LL)(n); ++i)
#define REM(i,a,n) for(LL i = ((n) - 1); i >= (a); --i)
#define FLOAT fixed << setprecision(16)
#define SPEEDUP {cin.tie(0); ios::sync_with_stdio(false);}
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
// all_of
// partial_sum, adjacent_difference

#ifdef ONLY_MY_ENVIR
#include "IntMod.h"
#include "Union_Find.h"
#include "Graph.h"
#include "Range.h"
#include "Global.h"
#include "Flow_Solver.h"
#include "Tree.h"
#include "Suffix_Array.h"
#include "Geometry.h"
#include "Matrix.h"
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
using PriorityQ = priority_queue<T, vector<T>, greater<T> >;	// コスト小を優先
#endif

int N, M;
int S, T;
vector<PP> G[100000];
LL dist1[100000];
LL dist2[100000];
MInt A[100000];
MInt B[100000];

void Dij(LL(&dist)[100000], MInt(&arr)[100000], int from) {
	Fill(dist, INFLL / 2);
	Fill(arr, 0);
	dist[from] = 0;
	arr[from] = 1;
	PriorityQ<PP> Q;
	Q.push(PP(0, from));

	while (!Q.empty()) {
		PP p = Q.top(); Q.pop();
		LL cost = p.first;
		int from = p.second;
		if (dist[from] < cost) continue;

		for (PP e : G[from]) {
			int to = e.first;
			LL new_dist = cost + e.second;
			if (new_dist < dist[to]) {
				arr[to] = arr[from];
			} else if(new_dist == dist[to]) {
				arr[to] += arr[from];
			}
			if (new_dist >= dist[to]) continue;
			dist[to] = new_dist;
			Q.push(PP(new_dist, to));
		}
	}
}



int main() {
	cin >> N >> M >> S >> T;
	--S; --T;
	
	REP(i, 0, M) {
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b;
		G[a].push_back(PP(b, c));
		G[b].push_back(PP(a, c));
	}

	Dij(dist1, A, S);
	Dij(dist2, B, T);

	MInt ans = A[T] * A[T];
	LL far = dist1[T];

	REP(i, 0, N) {
		if (dist1[i] * 2 == far) {
			ans -= A[i] * A[i] * B[i] * B[i];
		}
	}

	MInt sum = 0;
	REP(i, 0, N) {
		for (PP p : G[i]) {
			int j = p.first;
			if (dist1[i] + p.second + dist2[j] != far) continue;
			if (dist1[i] * 2 >= far || dist2[j] * 2 >= far) continue;
			sum += A[i] * A[i] * B[j] * B[j];
		}
	}
	cout << ans - sum << endl;
	return 0;
}
