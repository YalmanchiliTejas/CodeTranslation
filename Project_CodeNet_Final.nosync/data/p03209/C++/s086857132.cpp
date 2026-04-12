#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma warning(disable : 4996)
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<time.h>
#include<random>
#include<array>

using namespace std;

#define REP(i, n) for(int i = 0;i < n;++i)
#define REPR(i, n) for(int i = n-1;i >= 0;--i)
#define FOR(i, m, n) for(int i = m;i < n;++i)
#define FORR(i, m, n) for(int i = m-1;i >= n;--i)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end())
#define ll long long
#define pb push_back
#define print(x) cout<<(x)<<'\n'
#define pe(x) cout<<(x)<<" "
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define lb(v,n) lower_bound(v.begin(), v.end(), n)
#define ub(v,n) upper_bound(v.begin(), v.end(), n)
#define int long long
#define all(x) (x).begin(), (x).end()
#define print_space(v) REP(i,v.size())cout << v[i] << ((i == v.size() - 1) ? "\n" : " ")
template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7; const int MAX = 200020;
const double pi = acos(-1); const double EPS = 1e-12;
const ll INF = 1e18;
const int INT_INF = 1e9;

ll dp[60];
ll num(int n) {
	if (dp[n])return dp[n];
	if (n == 0) {
		dp[n] = 1;
		return 1;
	}
	dp[n] = 2 * num(n - 1) + 3;
	return dp[n];
}

ll pate[60];
ll get_pate(int n){
	if (pate[n])return pate[n];
	if (n == 0) {
		pate[n] = 1;
		return 1;
	}
	pate[n] = get_pate(n - 1) * 2 + 1;
	return pate[n];
}

ll calc(int n,int x) {
	if (x <= 0) return 0;
	if (n == 0) {
		return 1;
	}
	x--;
	ll res = 0;
	if (x >= num(n-1)) {
		res += get_pate(n - 1);
		x -= num(n - 1);
		if (x > 0) {
			x--;
			res++;
		}
		res += calc(n - 1, x);
		return res;
	}
	else {
		return calc(n - 1, x);
	}
}

void solve() {
	int n, x; cin >> n >> x;
	print(calc(n, x));
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//int q;cin>>q;
	//while(q--)
	solve();
}