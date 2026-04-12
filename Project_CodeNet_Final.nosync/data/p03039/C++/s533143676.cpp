#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <math.h>
#include <cmath>
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
#define all(x) (x).begin(),(x).end()
#define rep(i,m,n) for(int i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(int i = m;i >= n;--i)
#define INF INT_MAX/2
using namespace std;
using ll = long long;
using R = double;
using Data = pair<ll, vector<int>>;
const ll MOD = 1e9 + 7;
const ll inf = 1LL << 50;
struct edge { ll from; ll to; ll cost; };
typedef tuple<ll, ll, ll>T;
typedef pair<ll,ll>pll;

const int MAX = 202020;
ll fac[MAX], finv[MAX], inv[MAX];

void combinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}
ll comb(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
	ll n, m, k;
	cin >> n >> m >> k;

	combinit();
	ll ans = 0;

	ll sum1 = 0;
	for (ll j = 1; j <= m - 1; j++) {
		sum1 += (j * (j + 1)) / 2;
		sum1 %= MOD;
	}
	sum1 *= n * n;
	sum1 %= MOD;
	sum1 *= comb(m*n-2,k-2);
	ll sum2 = 0;
	for (ll j = 1; j <= n - 1; j++) {
		sum2 += (j * (j + 1)) / 2;
		sum2 %= MOD;
	}
	sum2 *= m * m;
	sum2 %= MOD;
	sum2 *= comb(m*n - 2, k - 2);
	ans = sum1 + sum2;
	ans %= MOD;
	cout << ans << endl;

	
	return 0;
}