# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
#include<limits.h>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<cstdio>
using namespace std;
typedef long long int ll;
const int N = 1000000;
const int mod = 1000000007;
const int INF = 1 << 30;
#define rep(i,n) for(ll i=(ll)0;i<(ll)n;++i)
#define ALL(x) x.begin(),x.end()
#define pp pair<ll,ll>
#define fi first
#define se second
#define pb push_back
ll ppow(ll x, ll n) {
	ll ans = 1;
	while (n > 0) {
		if ((n & 1) == 1)ans = ans * x;
		x = x * x;
		n >>= 1;
		x %= mod;
		ans %= mod;
	}
	return ans;
}
string YN(bool b) { return(b ? "YES" : "NO"); }
string yn(bool b) { return(b ? "Yes" : "No"); }
ll n,ans[2000020];
pp v[200020];
int main() {
	cin >> n;
	rep(i, n)cin >> v[i].first, v[i].second = i;
	sort(v, v + n);
	rep(i, n) {
		if (i < n / 2)ans[v[i].second] = v[n / 2].first;
		else ans[v[i].second] = v[n / 2 - 1].first;
	}
	rep(i, n)cout << ans[i] <<endl;
	return 0;
}