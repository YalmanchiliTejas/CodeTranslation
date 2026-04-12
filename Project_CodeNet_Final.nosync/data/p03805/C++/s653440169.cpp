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

int n, m;
// vector<vector<int>> g;
int g[10][10];

void solve() {
	cin >> n >> m;
    rep(i, 10) {
        rep(j, 10) {
            g[i][j] = 0;
        }
    }
    rep(i, m) {
        int a, b; cin >> a >> b; --a, --b;
        g[a][b] = g[b][a] = 1;
    }
    int dp[(1<<9)][10];
    rep(i, (1<<9)) {
        rep(j, 10) {
            dp[i][j] = 0;
        }
    }
    dp[(1<<0)][0] = 1;
    for(int bit = 1; bit < (1<<n); ++ bit) {
        rep(j, n) {
            rep(k, n) {
                if(j == k) continue;
                if(g[j][k] and bit & (1<<j) and !(bit & (1<<k))) {
                    dp[bit ^ (1<<k)][k] += dp[bit][j];
                }
            }
        }
    }
    int ans = 0;
    rep(i, n) {
        ans += dp[(1<<n) - 1][i];
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