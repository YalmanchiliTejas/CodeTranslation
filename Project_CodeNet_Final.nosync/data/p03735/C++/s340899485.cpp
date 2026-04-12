/**
 *    author:  otera    
**/
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<deque>
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

#define int long long
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60 ;
const ll mod=1e9+7 ;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve() {
	int n; cin >> n;
	vector<int> x(n), y(n);
	vector<P> ball(n);
	rep(i, n) {
		cin >> x[i] >> y[i];
		if(x[i] < y[i]) swap(x[i], y[i]);
		ball[i] = make_pair(x[i], y[i]);
	}
	sort(all(x));
	sort(all(y));
	int ans = (x[n - 1] - x[0]) * (y[n - 1] - y[0]);
	sort(all(ball));
	int rrange = x[n - 1] - y[0];
	priority_queue<int , vector<int>, greater<int>> pque;
	priority_queue<int> pque2;
	pque.push(ball[n - 1].sc);
	pque2.push(ball[n - 1].sc);
	for(int i = n - 2; i >= 0; --i) {
		int bmax = max(ball[i].fr, pque2.top());
		int bmin = min(ball[0].fr, pque.top());
		chmin(ans, rrange * (bmax - bmin));
		pque.push(ball[i].sc);
		pque2.push(ball[i].sc);
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}