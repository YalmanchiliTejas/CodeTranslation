#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;

vector<ll> layer;
vector<ll> patty;

ll solve(ll n, ll x)
{
	if(!x) return 0;
	if(x == layer[n]) return patty[n];
	if(x == layer[n] + 1) return patty[n] + 1;
	if(x > layer[n] + 1) return patty[n] + 1 + solve(n, x - layer[n] - 1);
	if(x < layer[n]) return solve(n - 1, x - 1);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(".in.txt", "r", stdin);
	freopen(".out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, x; cin >> n >> x;
	layer.resize(n + 1);
	patty.resize(n + 1);
	layer[0] = patty[0] = 1;
	for(int i = 1; i <= n; i++) layer[i] = 2 * layer[i - 1] + 3;
	for(int i = 1; i <= n; i++) patty[i] = 2 * patty[i - 1] + 1;
	cout << solve(n, x);

	return 0;
}