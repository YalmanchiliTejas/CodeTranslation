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
int main() {
	int x[8];
	rep(i, 8) {
		x[i] = i;
	}
	int n, m; cin >> n >> m;
	int out = 0;
	int d[8][8] = {};
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		d[a][b] = d[b][a] = 1;
	}
	bool f = true;
	rep(i, n-1) {
		if (!d[i][i + 1])f = false;
	}
	if (f)out++;
	while (next_permutation(x+1, x + n)) {
		f = true;
		rep(i, n-1) {
			if (!d[x[i]][x[i + 1]])f = false;
		}
		if (f)out++;
	}
	cout << out << endl;
	return 0;
}