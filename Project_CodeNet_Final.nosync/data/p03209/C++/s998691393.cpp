#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <set>
#include <tuple>
#include <algorithm>
#include <memory>
#include <numeric>
#include <queue>
#include <functional>
#include <cmath>
#include <cstring>
#include <map>
#include <unordered_map>

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;

const ll INF = 1LL << 60;

vector<ll> h_dp;
map<P, ll> f_dp;

ll h(const ll l)
{
	if (l < 1) return 1;
	if (h_dp[l] != -1) return h_dp[l];

	h_dp[l] = 2 * h(l - 1) + 3;
	return h_dp[l];
}


ll f(const ll l, const ll x)
{
	if (l <= 0) return (x > 0 ? 1 : 0);
	
	const auto& itr = f_dp.find(P(l, x));
	if (itr != f_dp.end())
	{
		return itr->second;
	}

	ll ans = 0;
	if (x <= 1 + h(l - 1))
	{
		ans = f(l - 1, x - 1);
	}
	else
	{
		ans = f(l - 1, h(l - 1)) + 1 + f(l - 1, x - 2 - h(l - 1));
	}

	f_dp.emplace(P(l, x), ans);
	return ans;
}


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N, X;

	cin >> N >> X;

	h_dp = vector<ll>(N + 1, -1);

	cout << f(N, X) << endl;
	//system("pause");
}
