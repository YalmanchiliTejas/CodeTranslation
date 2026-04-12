
/*****/

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>	//cout << fixed << setprecision(桁数);
#include <stdexcept>

//#define int long long

using namespace std;
using ll = long long;
using ld = long double;
using vecll = vector<ll>;

#define nextline() (std::cerr << "\n")
#define debug(x) (#x " : " + (x))
#define debug_cout(x) (std::cerr << #x << " : " <<  (x) << "\n")
#define debug_tabcout(n, x) (std::cerr << strMulti("\t",n) << #x << " : " <<  (x) << "\n")
#define debug_headcout(h, x) (std::cerr << h << " : " <<  (x) << "\n")
#define debug_tabheadcout(n, h, x) (std::cerr << strMulti("\t",n) << h << " : " <<  (x) << "\n")

#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; i++)
#define rep1(i, n) for(int i=1, i##_len=(n); i<=i##_len; i++)
#define rrep(i, n) for(int i=(n)-1; i >= 0; i--)
#define rrep1(i, n) for(int i=(n); i > 0; i--)
#define all(x) (x).begin(), (x).end()
#define pair(a, b) make_pair(a, b);
constexpr int INF = 2000000100;
constexpr ll DIV = 1000000007;	// 10e9+7
template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
//template<class T> T divup(T a, T b) { if (a % b == 0) { return a / b; } return a / b + 1; }
#define diup(a, b) (a % b == 0 ? a / b : a / b + 1)
std::string strMulti(std::string t, int n) { std::string out = ""; for (int i = 0; i < n; i++) { out += t; } return out; }
template<class T> T math_P(T m, T n) { T ret = 1; for (T i = m; i > m - n; i--) { ret *= i; } return ret; }
template<class T> T math_C(T m, T n) { T ret = mathP(m, n); for (T i = 2; i <= n; i++) { ret /= i; } return ret; }
template<class T> bool compare_by_b(pair<T, T> a, pair<T, T> b) { if (a.second != b.second) { return a.second < b.second; } return a.first < b.first; }
template<class T> T math_gcd(T a, T b) { a = abs(a); b = abs(b); if (a < b) { std::swap(a, b); } T tmp; while (b != 0) { tmp = b; b = a % b; a = tmp; } return a; }
template<class T> T math_lcm(T a, T b) { a = abs(a); b = abs(b); if (a > b) { std::swap(a, b); } if (a == 1) { return b; } T i = a; while (i % b != 0) { i += a; } return i; }

/*****/

void Main()
{
	char c;
	cin >> c;
	if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
		cout << "vowel";
	else
		cout << "consonant";
}

/*****/

int main()
{
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);

	std::cout << std::fixed << std::setprecision(10);


	/*
	while (true)
	{
		Main();
		cout << endl;
	}
	//*/


	Main();

	return 0;
}
