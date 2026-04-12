#include <cmath>
#include <cstdio>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <stdio.h>
#include <functional>
#include <chrono>
using namespace std;

#define rep(i,s,n) for(ll i=s;i<(n);++i)
using ll = long long;
using pll = pair<ll, ll>;
constexpr ll INF = (1LL << 60);
constexpr ll MAX_INF = 9223372036854775807;
constexpr ll MOD = (1e9 + 7);
//constexpr ll MOD = (998244353);

using vl = vector<ll>;
using vvl = vector<vector<ll>>;

template<class T>
vector<vector<T>> vvt(T init, ll m, ll n) {
	vector<vector<T>> ans = vector<vector<T>>(m, vector<T>(n, init));
	return move(ans);
}

template<class T>
vector<T> vt(T init, ll n) {
	vector<T> ans = vector<T>(n, init);
	return move(ans);
}

template<class T>
T maxVec(vector<T>& v) {
	T ans = -INF;
	rep(i, 0, v.size()) {
		ans = max(ans, v[i]);
	}
	return ans;
}

// 素数判定
bool judge(ll n) {
	for (ll i = 2; i * i <= n; i++) if (n %= i)return false;
	return true;
}


template <class C>
void print(const C & c, std::ostream & os = std::cout)
{
	std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, ", "));
	os << std::endl;
}
/*
ll count(ll n,ll r) {
	ll ans = 0,check = 1;
	rep(i,0, r) {
		if ((n & check) > 0) {
			ans++;
		}
		check = check << 1;
	}
	return ans;
}
*/
bool sortreverse(ll a, ll b) {
	return a > b;
}

ll kiriage(ll a, ll b) {
	if (a % b == 0)return a / b;
	return a / b + 1;
}

ll n, m, x, y, t, q, s;

int main() {
	cin >> n;
	vl a(n);
	rep(i, 0, n) {
		cin >> a[i];
	}
	map<ll,ll> check;
	rep(i, 0, n) {
		auto itr = check.lower_bound(a[i]);
		//printf("#%d\n",(--itr) == check.end());
		if (itr == check.begin()) {
			itr = check.end();
		}
		else {
			itr--;
		}
		if (itr != check.end()) {
			if (itr->second == 1)check.erase(itr->first);
			else check[itr->first]--;
		}
		
		if (check.find(a[i]) != check.end()) {
			check[a[i]] ++;
		}
		else {
			check[a[i]] = 1;
		}
	}
	ll ans = 0;
	for (auto itr = check.begin(); itr != check.end(); ++itr) {
		ans += itr->second;
	}
	printf("%lld\n", ans);
}