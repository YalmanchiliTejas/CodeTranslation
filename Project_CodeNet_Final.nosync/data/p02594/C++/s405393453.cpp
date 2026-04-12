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
#include <sstream>
#include <bitset>

#define roop(i, n) for(int i=0;i<n;i++)
#define DIV 1000000007
#define MOD ((int)1e9+7)
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

struct Combination {
	const int num=51e4;			//要素数
	const int mod=1e9+7;
	vector<ll> fact,inv,finv; //階乗,逆元,逆元の階乗.
	
	Combination():fact(num),inv(num),finv(num){
		fact[0]=fact[1]=1;
		inv[1]=1;
		finv[0]=finv[1]=1;
		for(int i=2;i<num;++i){
			fact[i]=fact[i-1]*i%mod;
			inv[i]=mod-inv[mod%i]*(mod/i)%mod;
			finv[i]=finv[i-1]*inv[i]%mod;
		}
	}
	
	int nCk(int n,int k){
		if(n<k) return 0;
		if(n<0 or k<0) return 0;
		return fact[n]*(finv[k]*finv[n-k]%mod)%mod;
	}
	int big_nCk(int n,int k){ //nが大きいとき
		ll res=1LL;
		for (int i = 0; i < k; i++) {
			res=res*(n-i)%mod;
		}
		res = res*finv[k]%mod;
		return res;
	}
	int nHk(int n,int k){return nCk(n+k-1,n-1);}//重複組み合わせ.
};

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

ll pow_mod(ll n, ll k, ll p) { // n^k(mod p)
	if (k == 0) {
		return 1;
	}
	ll res = pow_mod(n * n % p, k / 2, p);
	if (k & 1) {
		res = res * n % p;
	}
	return res;
}

bool vector_finder(std::vector<int> vec, int number) { // vector 内にnumberがあるかどうか
	auto itr = std::find(vec.begin(), vec.end(), number);
	size_t index = std::distance( vec.begin(), itr );
	if (index != vec.size()) { // 発見できたとき
		return true;
	}
	else { // 発見できなかったとき
		return false;
	}
}

int main() {
	int x; 
	cin >> x;
	if (x >= 30) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}