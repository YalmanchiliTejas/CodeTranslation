#include <cmath>
#include <cstdio>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stdio.h>
#include <functional>
#include <chrono>
using namespace std;

#define rep(i,s,n) for(ll i=s;i<(n);++i)
using ll = long long;
using pll = pair<ll, ll>;
constexpr ll INF = (1LL << 60);
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
vector<T> vt(T init,ll n) {
	vector<T> ans = vector<T>(n, init);
	return move(ans);
}

template<class T>
T maxVec(vector<T> &v) {
	T ans = -INF;
	rep(i,0, v.size()) {
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
void print(const C& c, std::ostream& os = std::cout)
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

bool kansu(pll a, pll b) {
	return a.first < b.first;
}

ll kiriage(ll a, ll b) {
	if (a % b == 0)return a / b;
	return a / b + 1;
}

ll n,d;
string k;
ll dp[10003][103][2];



int main() {
	cin >> k;
	cin >> d;
	ll goukei = 0;
	dp[0][0][0] = 1;
	rep(i, 0, k.size()) {
		n = ll(k[i]) - ll('0');
		goukei += n; goukei %= d;
		dp[i + 1][goukei][0] = 1;
	}
	rep(i, 0, k.size()) {
		n = ll(k[i]) - ll('0');
		rep(j, 0, d) {
			rep(l, 0, n) {
				dp[i + 1][(j + l) % d][1] += dp[i][j][0];
				dp[i + 1][(j + l) % d][1] %= MOD;
			}
			rep(l, 0, 10) {
				dp[i + 1][(j + l) % d][1] += dp[i][j][1];
				dp[i + 1][(j + l) % d][1] %= MOD;
			}

		}
	}
	printf("%lld\n", (MOD + (dp[k.size()][0][0] + dp[k.size()][0][1]) % MOD - 1) % MOD);
}