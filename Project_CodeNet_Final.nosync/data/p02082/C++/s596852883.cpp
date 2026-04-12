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
#include<utility>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll INF = mod * mod;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define stop char nyaa;cin>>nyaa;

void solve() {
	ll s, t, p, q, m, y;
	cin >> s >> t >> p >> q >> m >> y;
	cout << (s^t^y) << endl;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
//stop
	return 0;
}
