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
const ll mod = 1000000007;
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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
char t[50][50];
bool used[50][50];
vector<P> v;
P g;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool add(P x) {
	rep(k, 4) {
		int nx = x.first + dx[k];
		int ny = x.second + dy[k];
		if (P{ nx,ny } == g) {
			v.push_back({ nx,ny });
			return true;
		}
		if (nx < 0 || ny < 0 || nx == 50 || ny == 50)continue;
		if (t[nx][ny] == '#')continue;
		if (used[nx][ny])continue;
		used[nx][ny] = true;
		if (add({ nx,ny })) {
			v.push_back({ nx,ny }); return true;
		}
	}
	return false;
}
struct cost { ll keep, on, off; };
cost c[50][50];
int w, h, m;
vector<int> loc[50][50];
void solve() {
	rep(i, 50) {
		rep(j, 50) {
			t[i][j] = '#';
		}
	}
	cin >> h >> w >> m;
	rep(i, h) {
		rep(j, w) {
			cin >> t[i][j];
		}
	}
	rep(i, h) {
		rep(j, w) {
			cin >> c[i][j].keep;
		}
	}
	rep(i, h) {
		rep(j, w) {
			cin >> c[i][j].on;
		}
	}
	rep(i, h) {
		rep(j, w) {
			cin >> c[i][j].off;
		}
	}
	P memo;
	cin >> memo.first >> memo.second;
	v.push_back(memo);
	rep(i, m-1) {
		rep(j, 50) {
			rep(k, 50) {
				used[j][k] = false;
			}
		}
		int x, y; cin >> x >> y;
		g = { x,y };
		used[memo.first][memo.second] = true;
		int l1 = v.size();
		add(memo);
		memo = g;
		reverse(v.begin() + l1, v.end());
	}
	ll out = 0;
	int len = v.size();
	rep(i, len) {
		loc[v[i].first][v[i].second].push_back(i);
	}
	rep(i, h) {
		rep(j, w) {
			int len2 = loc[i][j].size();
			if (len2)out += c[i][j].on;
			rep(k, len2) {
				if (k == len2 - 1) {
					out += c[i][j].off;
				}
				else {
					out += min(c[i][j].on + c[i][j].off, c[i][j].keep*(loc[i][j][k + 1] - loc[i][j][k]));
				}
			}
		}
	}
	cout << out << endl;
}
int main(){
	solve();
	return 0;
}
