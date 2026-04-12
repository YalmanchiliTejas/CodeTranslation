#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <numeric>
#include <iomanip>
#include <limits>

#define roop(i, n) for(int i=0;i<n;i++)
#define DIV 1000000007
//static const long double pi = 3.1415926535897932;

using namespace std;
using ll = long long int;
using ull = unsigned long long;

char toSmall(char c) { // 大文字を小文字へ
	return (c + 0x20);
}

char toLarge(char c) { // 小文字を大文字へ
	return (c - 0x20);
}

float myPower(int a, int n) { // aのn乗の計算
	float x = 1;
	while (n > 0) { // 全てのbitが捨てられるまで
		if ( n & 1) { // 一番右のbitが１のとき
			x *= a;
		}
		a *= a;
		n >>= 1; // bit全体を右に1つシフトして一番右を捨てる
	}
	return x;
}

ll combination(ll n, ll r) { // nCr の計算
	if (n < 0 || r < 0 || r > n) return -1;

	if (n - r < r) r = n - r;
	if (r == 0) return 1;
	if (r == 1) return n;

	vector<ll> num(r);
	vector<ll> den(r);

	for (ll i = 0; i < r; i++) {
		num[i] = n - r + i + 1;
		den[i] = i + 1;
	}

	for (ll p = 2; p <= r; p++) {
		ll pivot = den[p - 1];
		if (pivot > 1) {
			ll offset = (n - r) % p;
			for (ll k = p - 1; k < r; k += p) {
				num[k - offset] /= pivot;
				den[k] /= pivot;
			}
		}
	}
	ll result = 1;
	for (ll k = 0; k < r; k++) {
		if (num[k] > 1) result *= num[k];
	}
	return result;
}

vector<string> split(const string& src, const char* delim = ",") { //カンマ区切り
	vector<string> vec;
	string::size_type len = src.length();

	for (string::size_type i = 0, n; i < len; i = n + 1) {
		n = src.find_first_of(delim, i);
		if (n == string::npos) {
			n = len;
		}
		vec.push_back(src.substr(i, n - i));
	}

	return vec;
}

bool check_int(string str)
{
	if (all_of(str.cbegin(), str.cend(), [](char ch) { return isdigit(ch);}))
	{
		return true;
	}
	return false;
}

struct rest {
	string s;
	int p;
	int num;

	/* -------------------------------------
	sort関数を使用したときのソートの定義をする。
	まずは文字列sでソートする。
	文字列sが同じだった場合、pでソートする。
	この条件を参考演算子で表現(ifでもOK)
	-------------------------------------*/
	bool operator<(const rest& right) const {
		return s == right.s ? p > right.p : s < right.s;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	if (n == m) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}