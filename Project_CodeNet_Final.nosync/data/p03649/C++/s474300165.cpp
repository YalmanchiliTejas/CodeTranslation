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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll MOD = (1e+9)+7;
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
typedef pair<P, int> PP;
ll a[50];int n; 
bool ok() {
	bool res = true;
	rep(i, n) {
		if (a[i] >= n)res = false;
	}
	return res;
}
ll calsum() {
	ll res = 0;
	rep(i, n) {
		res += a[i];
	}
	return res;
}
int main() {
	cin >> n;
	ll sum = 0;
	rep(i, n) {
		cin >> a[i]; sum += a[i];
	}
	ll key = n * (n - 1);
	ll out = 0;
	if (sum < key) {
		while (!ok()) {
			sort(a, a + n,greater<ll>());
			out += a[0] / (ll)n;
			Rep(i, 1, n) {
				a[i] += a[0] / (ll)n;
			}
			a[0] %= n;
		}
	}
	else {
		rep(i, n) {
			a[i] %= (ll)(n + 1);
		}
		ll ma = 0;
		rep(i, n+1) {
			if (ok()) {
				ma = max(ma, calsum());
			}
			rep(j, n) {
				a[j] = (a[j] + 1) % (n + 1);
			}
		}
		out = sum - ma;
	}
	cout << out << endl;
	return 0;
}