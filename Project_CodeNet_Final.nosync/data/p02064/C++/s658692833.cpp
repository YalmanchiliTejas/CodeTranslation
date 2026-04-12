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
#include <numeric>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long MAX = 5100000;
const long long INF = 1LL << 60;
const long long mod = 1000000007LL;
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
	ll N, s, t; scanf("%lld %lld %lld", &N, &s, &t);
	vector<ll> ds(N + 5), dt(N + 5);
	for (ll i = 1; i <= N; i++) {
		if (i == s) continue;
		cout << "? " << s << " " << i << endl;
		ll x; scanf("%lld", &x);
		ds[i] = x;
	}
	for (ll i = 1; i <= N; i++) {
		if (i == t) continue;
		cout << "? " << t << " " << i << endl;
		ll x; scanf("%lld", &x);
		dt[i] = x;
	}
	vector<pair<ll, ll>> v;
	for (ll i = 1; i <= N; i++) {
		if (i == s || i == t) continue;
		if (ds[i] + dt[i] == ds[t]) {
			v.emplace_back(ds[i], i);
		}
	}
	sort(v.begin(), v.end());
	vector<ll> res;
	if(v.size() > 0 ) res.push_back(v[0].second);
	for (ll i = 1; i < v.size(); i++) {
		cout << "? " << res.back() << " " << v[i].second << endl;
		ll x; scanf("%lld", &x);
		if (ds[res.back()] + x == ds[v[i].second]) {
			res.push_back(v[i].second);
		}
	}
	cout << "! " << s;
	for (ll i = 0; i < res.size(); i++) {
		cout << " " << res[i];
	}
	cout << " " << t << endl;
	return 0;
}
