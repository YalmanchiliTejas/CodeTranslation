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
const ll mod = 1000000007;
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

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int h, w;
char mp[50][50];

void solve() {
	rep(i, h) {
		rep(j, w) {
			cin >> mp[i][j];
		}
	}
	vector<int> v;
	int x = 0, y = 0, d = 2;
	while (true) {
		//cout << x << " " << y <<" "<<d<< endl;
		int nx, ny;
		rep(j, 4) {
			int nd = d + 1 - j;
			nd = (nd % 4 + 4) % 4;
			nx = x + dx[nd], ny = y + dy[nd];
			if (nx < 0 || ny < 0 || nx >= h || ny >= w)continue;
			if (mp[nx][ny] == '.') {
				v.push_back(nx*w + ny);
				x = nx, y = ny, d = nd;
				break;
			}
		}
		if (x == 0 && y == 0)break;
	}
	vector<bool> exi(h*w, false);
	rep(i, v.size()) {
		//cout << v[i] << endl;
		if (exi[v[i]]) {
			int j = i - 1;
			while (v[j] != v[i]) {
				exi[v[j]] = false;
				j--;
			}
		}
		else {
			exi[v[i]] = true;
		}
	}
	if (exi[w - 1] && exi[(h - 1)*w] && exi[h*w - 1]) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cout << fixed << setprecision(10);
	//init();
	while (cin >> h >> w, h) {
		solve();
	}
	//stop
		return 0;
}
