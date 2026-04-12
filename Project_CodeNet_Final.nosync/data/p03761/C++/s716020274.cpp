#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <algorithm>  // std::unique
#include <cmath>
#include <limits.h>
#include <queue>
#include <unordered_map>
#include <sstream>      // std::ostringstream
#include <bitset>
#include <iomanip>
#include <functional>
#include <set>
#include <list>

#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

using ll = long long;
constexpr auto PrimeBigNum10_9_7 = 1000000007;
const long long INF = 1LL << 60;

#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define repb(i,a,b) for(ll i=a;i>=b;--i)

template <typename T>
void DisplayAnswer(const T& v) {
	cout << v << endl;
}
template <typename T>
void DisplayAnswers(const vector<T>& vs) {
	for (const auto& v : vs) {
		cout << v << endl;
	}
}

template <typename T>
void DisplayAnswerOneLine(const vector<T>& vs) {
	for (const auto& v : vs) {
		cout << v << ' ';
	}
	cout << endl;
}


std::vector<std::string> split(const std::string &str, char sep)
{
	std::vector<std::string> v;
	std::stringstream ss(str);
	std::string buffer;
	while (std::getline(ss, buffer, sep)) {
		v.push_back(buffer);
	}
	return v;
}



template<class T>
void chmin(T& a, T b) {
	if (a > b) {
		a = b;
	}
}


// 素数判定
template <typename T>
bool IsPrimeNumber(T value) {

	for (int i = 2; i * i <= value; ++i) {
		if ((value % i) == 0) {
			return true;
		}
	}
	return false;
}

// 桁数判定
template <typename T>
T GetFigureLength(T value) {
	T figure = 1;
	while (value >= 10) {
		value /= 10;
		++figure;
	}
	return figure;
}

// 素因数分解結果
template <typename T>
map<T, T> GetPrimeFactorize(T value) {

	map<T, T> res;

	for (T i = 2; i * i <= value; ++i) {
		if ((value%i) != 0)	continue;

		T count = 0;
		while ((value % i) == 0) {
			value /= i;
			++count;
		}

		res[i] = count;
	}

	if (value != 1) {
		res[value] = 1;
	}
	return res;
}


void DebugPrint(const vector<ll>& vec) {
	cout << "{";
	for (auto itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << ",";
	}
	cout << "}" << endl;
}

// valueが2のx乗以下である計算
ll calc2x(ll value) {
	ll n = 0;
	while (value > 0) {
		value /= 2;
		++n;
	}
	return n;
}
int main(void) {

	ll N;
	cin >> N;

	vector<map<char, ll>> vec(N);

	for (ll i = 0; i < N; ++i) {
		string str;
		cin >> str;
		for (const auto& c : str) {
			vec[i][c]++;
		}
	}

	string answer = "";
	for (char c = 'a'; c <= 'z'; ++c) {
		
		ll n = 100;
		for (const auto& v : vec) {
			if (v.count(c) > 0) {
				n = min(n, v.at(c));
			}
			else {
				n = 0;
				break;
			}
		}
		for (ll i = 0; i < n; ++i) {
			answer.push_back(c);
		}
	}

	cout << answer << endl;

	
	return 0;
}
