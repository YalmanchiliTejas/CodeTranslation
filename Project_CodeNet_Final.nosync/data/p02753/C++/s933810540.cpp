#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>
#include <stdio.h>
#include <numeric>
#include <cmath>
#include <limits>
#include <bitset> 
#include <iterator> 
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include<deque>
#include <regex>
#include <list> 
#define rep(i,n) for(ll i=0;i<(n); ++i)
#define per(i,n) for(ll i=n-1;i>=0; --i)
#define all(x) (x).begin(),(x).end()
#define _GLIBCXX_DEBUG
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
typedef long long ll;
const ll MOD = 1000000007;
ll getDigit(ll n) {
	ll cnt = 0;
	while (n != 0) {
		n /= 10;
		cnt++;
	}
	return cnt;
}
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
typedef pair<double, long long> pair_t;
bool comp(const pair_t& a, const pair_t& b) {
	if (a.first == b.first)return  a.second > b.second;
	else {
		return a.first > b.first;
	}
}

int main() {
	string s;
	cin >> s;
	for (ll i = 0; i < s.length()-1; i++) {
		if (s[i] != s[i + 1])return cout << "Yes" << endl,0;
	}
	cout << "No" << endl;
}
