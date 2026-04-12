#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <cmath>
#include <limits>
#include <utility>
#include <map>
#include <iomanip>
#include <queue>
#include <cctype>
#include <stack>
#include <random>
#include <list>
#include <numeric>
#include <chrono>
#include <set>


#define rep(i,p,q) for(ll i = p;i < q;i++)
#define ll long long

using namespace std;


const long long MAX_N = 1 << 17;

long long dat[2 * MAX_N - 1];

ll ecd(ll a, ll b) {
	if (a < b) swap(a, b);
	if (b == 0) return a;
	else {
		return ecd(b, a % b);
	}
}

ll pow(ll a, ll b) {
	vector<ll> d = vector<ll>((ll)(log(b)) + 2);
	d[0] = a;
	rep(i, 1, d.size()) d[i] = d[i - 1] * d[i - 1];
	ll ret = 1;
	rep(i, 0, log(b) + 1) {
		if (b & 1 << i) ret *= d[i];
	}
	return ret;
}

//L
vector<ll> a;
ll N;
vector<vector<vector<ll>>> dp;
vector<vector<vector<ll>>> vis;

//status == 0 なら太郎君,1なら次郎くん
ll rec(ll i, ll j, ll status) {
	if (i > j) return 0;

	if (vis[i][j][status] == 1) return dp[i][j][status];


	vis[i][j][status] = 1;

	if (status) {
		return dp[i][j][status] = min(rec(i, j - 1, !status) - a[j], rec(i + 1, j, !status) - a[i]);
	}
	else {
		return dp[i][j][status] = max(rec(i, j - 1, !status) + a[j], rec(i + 1, j, !status) + a[i]);
	}
}

int main(void) {
	cin >> N;
	a = vector<ll>(N);
	rep(i, 0, N) cin >> a[i];
	dp = vector<vector<vector<ll>>>(N, vector<vector<ll>>(N, vector<ll>(2,0)));
	vis = vector<vector<vector<ll>>>(N, vector<vector<ll>>(N, vector<ll>(2,0)));

	ll sum = 0;
	cout << rec(0,N-1,0) << endl;
}