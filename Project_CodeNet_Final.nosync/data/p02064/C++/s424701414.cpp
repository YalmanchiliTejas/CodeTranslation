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
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<int> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

int query(int u, int v) {
	cout << "? " << u+1 << " " << v+1 << endl;
	int ret; cin >> ret;
	return ret;
}
void solve() {
	int n, s, t; cin >> n >> s >> t; s--; t--;
	int d = query(s, t);
	vector<P> v;
	rep(i, n) {
		if (i == s || i == t)continue;
		int d1 = query(s, i);
		int d2 = query(i,t);
		if (d1 + d2 == d) {
			v.push_back({ d1,i });
		}
	}
	sort(v.begin(), v.end());
	vector<int> ans; ans.push_back(s);
	if (v.size() == 0) {
		cout << "! " << s << " " << t << endl; return;
	}
	ans.push_back(v[0].second);
	int cur = 0;
	for (int i = 1; i < v.size(); i++) {
		int dist = query(v[cur].second, v[i].second);
		if (v[i].first - v[cur].first == dist) {
			ans.push_back(v[i].second); cur = i;
		}
	}
	ans.push_back(t);
	cout << "!";
	rep(i, ans.size()) {
		cout << " " << ans[i]+1;
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cout << fixed << setprecision(10);
	//init();
	solve();
	//stop
	return 0;
}

