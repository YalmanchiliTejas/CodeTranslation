#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <tuple>
#include <assert.h>
#include <deque>
#include <bitset>
#include <iomanip>
#include <limits>
#include <chrono>
#include <random>
#include <array>
#include <unordered_map>
#include <functional>
#include <complex>

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long MAX = 5100000;
const long long INF = 1LL << 60;
const int inf = 1 << 28;
//const long long mod = 1000000007LL;
//const long long mod = 998244353LL;

using namespace std;
typedef unsigned long long ull;
typedef long long ll;


int main()
{
	/*
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	*/
	vector<char> right = { 'y','u','i','o','p','h','j','k','l','n','m' };
	sort(right.begin(), right.end());
	while (1) {
		string s; cin >> s; if (s == "#") break;
		string t;
		for (ll i = 0; i < s.size(); i++) {
			if (binary_search(right.begin(), right.end(), s[i])) t += '1';
			else t += '0';
		}
		t.erase(unique(t.begin(), t.end()), t.end());
		printf("%lld\n", (ll)t.size() - 1);
	}
	return 0;
	/*
		おまじないを使ったらscanfとprintf関連注意！！！！！！！！！！！！
	*/
}
