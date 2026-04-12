#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000009;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;
ll l[51];
ll p[51];
void init() {
	l[0] = 1;
	rep1(i, 50) {
		l[i] = l[i - 1] * 2 + 3;
	}
	p[0] = 1;
	rep1(i, 50) {
		p[i] = p[i - 1] * 2 + 1;
	}
}
ll dfs(int n, ll x) {
	if (x == 0)return 0;
	if (n == 0)return 1;
	ll res = 0;
	if (x <= l[n - 1] + 1) {
		res += dfs(n - 1, x-1);
	}
	else if (x == l[n - 1] + 2) {
		res += dfs(n - 1, x-2) + 1;
	}
	else {
		res += p[n - 1]+1;
		if (x == l[n])x--;
		res += dfs(n - 1, x - (l[n - 1] + 2));
	}
	return res;
}
int main() {
	init();
	int n; ll x; cin >> n >> x;
	cout << dfs(n, x) << endl;
	return 0;
}
