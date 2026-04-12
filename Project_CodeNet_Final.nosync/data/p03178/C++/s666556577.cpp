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
const ld eps = 1e-3;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;

ll dp[10001][100];
string k; int d;
void init() {
	dp[0][0] = 1;
	rep(i, 10000) {
		rep(j, d) {
			rep(k, 10) {
				(dp[i + 1][(j + k) % d] += dp[i][j]) %= mod;
			}
		}
	}
}
int main() {
	cin >> k >> d;
	init();
	int n = k.length();
	ll ans = 0; int sum = 0;
	rep(i,n){
		int t = k[i] - '0';
		rep(j, t) {
			int csum = sum + j; csum %= d; csum = (d - csum) % d;
			ans += dp[n - i - 1][csum]; ans %= mod;
		}
		sum += t; sum %= d;
	}
	if (sum == 0)ans++;
	cout << (ans-1+mod)%mod << endl;
	//stop
	return 0;
}