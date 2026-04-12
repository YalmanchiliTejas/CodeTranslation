#ifndef __INTMOD_H__0001__
#define __INTMOD_H__0001__

#include <vector>
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
	/* 素数判定は自分でしろ */
	IntMod Inverse() const {
		return (*this).Pow(Modulus - 2);
	}
	IntMod Pow(unsigned int exp) const {
		unsigned int arr[32];		// 32じゃなくてもいい
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
	unsigned int Get_value() const {
		return value_m;
	}
};

#endif

//#include "IntMod.h"
typedef IntMod<1000000007> MInt;

//#include "Union_Find.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
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
#include <numeric>
#include <list>
#include <bitset>

using namespace std;
#define REP(i,a,n) for(int i = (a); i < (int)(n); ++i)
#define REPM(i,n,a) for(int i = ((n) - 1); i >= (a); --i)
#define EPS 0.0001
#define INF 0x3FFFFFFF
#define INFLL 0x3FFFFFFF3FFFFFFF
#define INFD 1.0e+308
#define FLOAT setprecision(16)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL, LL> PP;

template <class T, class U>
istream& operator>>(istream& ist, pair<T, U>& right) { return ist >> right.first >> right.second; }
template <class T, class U>
ostream& operator<<(ostream& ost, pair<T, U>& right) { return ost << right.first << ' ' << right.second; }
template <class T, class TCompatible, size_t N>
void Fill(T(&dest)[N], const TCompatible& val) { fill(begin(dest), end(dest), val); }
template <class T, class TCompatible, size_t M, size_t N>
void Fill(T(&dest)[M][N], const TCompatible& val) { for (int i = 0; i < M; ++i) Fill(dest[i], val); }
//sum, 累積和
// 負のときの割り算に注意
#if 1
#include <array>
#include <unordered_set>
#include <unordered_map>
template<class T>
using PriorityQ = priority_queue<T, vector<T>, greater<T> >;	// コスト小を優先
#endif

//#include "Union_Find.h"

int N, A, B, C, D;
MInt DP[1001][1001];
int main() {
	cin >> N >> A >> B >> C >> D;
	DP[A - 1][0] = 1;
	REP(i, A, B + 1){
		REP(j, 0, N + 1) {
			DP[i][j] += DP[i - 1][j];
			REP(k, C, min(D, (N - j) / i) + 1) {
				DP[i][j + i * k] += MInt(j + i * k).Fact()
					/ (MInt(j).Fact() * MInt(i).Fact().Pow(k) * MInt(k).Fact())
					* DP[i - 1][j];
			}
		}
	}
	cout << DP[B][N].Get_value() << endl;
	return 0;
}