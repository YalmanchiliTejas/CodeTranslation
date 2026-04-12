#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<queue>
#include<stack>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<cctype>
#include<iomanip>
#include<limits>
#include<bitset>

using namespace std;
typedef long long int ll; typedef pair<int, int> P; typedef unsigned long long int ull;
const ll mod = 1e9 + 7;
const int inf = 1e9 + 7;
const ll linf = 1LL << 60;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define REP(i,m,n) for(int i=(m);i<(int)n;i++)
#define all(a) (a).begin(),(a).end()
#define allg(a) (a).begin(),(a).end(),greater<>()
#define SUM(a) accumulate((a).begin(),(a).end(),0)
#define d10 std::setprecision(10)
#define d20 std::setprecision(20)
#define vec vector<int>
#define vecb vector<bool>
#define vecd vector<double>
using str = string;
const double PI = 3.14159265359;
ll gcd(ll a, ll b) { ll t; while (b != 0) { t = a % b; a = b; b = t; }return a; }
int gcd(int a, int b) { int t; while (b != 0) { t = a % b; a = b; b = t; }return a; }
ll recfact(ll start, ll n) {
	ll i;
	if (n <= 16) {
		ll r = start;
		for (i = start + 1; i < start + n; i++) r = r * i % mod;
		return r % mod;
	}
	i = n / 2;
	return recfact(start, i) % mod * recfact(start + i, n - i) % mod;
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}
ll fct(ll n) { return recfact(1, n); }
ll ncm(ll n, ll m) {
	if (n < m)return 0;
	ll x = (fct(n) % mod / (fct(m) * fct(n - m)) % mod) % mod;
	return x;
}
std::string sreverse(string str, int firstItr, int secondItr) {
	if (firstItr < 0 || secondItr>int(str.size() - 1))return str;
	while (firstItr < secondItr) {
		swap(str[firstItr], str[secondItr]);
		firstItr++; secondItr--;
	}
	return str;
}
std::string RunLengthEncoding(std::string str) {
	int itr = 0; std::string res;
	while (itr < int(str.size())) {
		char tmp = str[itr++];
		int length = 1;
		while (itr <int(str.size()) && str[itr] == tmp) { ++itr; ++length; }
		res.push_back(tmp);
		res += to_string(length);
	}
	return res;
}
std::string split(std::string str, size_t first_itr, bool isFront) {
	if (first_itr < 0 || first_itr > str.size()) {
		return str;
	}
	else {
		if (isFront) {
			std::string tmp;
			for (size_t i = 0; i < first_itr; i++) {
				tmp.push_back(str.at(i));
			}
			return tmp;
		}
		else {
			std::string tmp;
			for (size_t i = first_itr; i < str.size(); i++) {
				tmp.push_back(str.at(i));
			}
			return tmp;
		}
	}
}


bool dfs(int depth, str s) {
	/*if (depth == n) {
		ans.push_back(s);
		return false;
	}
	for (int i = 0; i < n; i++) {
		if (dfs(depth + 1, s + dic.at(i))) {
			return true;
		}
	}*/
	return false;
}


int main() {
	bool a = 0, b = 0;
	rep(i, 3) {
		char tmp;
		cin >> tmp;
		if (tmp == 'A')
			a = 1;
		else
			b = 1;
	}

	cout << (a && b ? "Yes" : "No") << endl;

	return 0;
}