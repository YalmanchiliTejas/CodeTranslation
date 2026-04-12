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
#include<utility>
#include<cassert>
using namespace std;

typedef long long  ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef double ld;
typedef complex<ld> Point;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
typedef vector<int> vec;

ll sup = 1000000000000000000;
const int mn = 2000;
ll pas[mn][mn];
void solve() {
	rep(i, mn) {
		rep(j, mn) {
			if (i == 0 || j == 0)pas[i][j] = 1;
			else {
				pas[i][j] = (pas[i - 1][j] + pas[i][j - 1]);
			}
		}
	}
	int d = 1;
	vector<ll> v;
	for (int i = 0; i < 650;i+=d) {
		if (pas[7][i] > sup)break;
		v.push_back(pas[7][i]);
		//cout << pas[7][i] << endl;
	}
	vector<int> c(v.size(),0);
	//cout << v.size() << endl;
	ll k; cin >> k;
	int sz = 0;
	per(i, v.size()) {
		if (v[i] <= k) {
			if (sz == 0)sz = i + 1;
			int cnt = 0;
			while (k >= v[i]) {
				cnt++; k -= v[i];
			}
			c[i] = cnt;
		}
	}
	string s;
	string t = "FESTIVA";
	rep(i, sz) {
		s += t;
		rep(j, c[i])s.push_back('L');
		rep(j, d - 1)s += t;
	}
	//cout << s.size() << endl;
	cout << s << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(5);
	//while (cin >> n)solve();
	solve();
	//stop
	return 0;
}