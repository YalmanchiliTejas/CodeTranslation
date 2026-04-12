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
using namespace std;
typedef long long ll;
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
#define fr first
#define sc second

string c;
ll dp[10001][2];
//index,nonzero,lower
ll dp0[10001][2][2];
ll calc(string s) {
	ll ret = 0;
	int len = c.length();
	int l = s.length();
	if (len > l)return 0;
	else if (len == l && c > s)return 0;
	if (c == "0") {
		//誰だよこんなケース作った人！！c>0にしてくれよ！！
		///guilty
		for (int i = 0; i < l - len + 1; i++) {
			dp0[0][0][0] = 1;
			rep(j, l) {
				rep(x, 2)rep(y, 2)dp0[j + 1][x][y] = 0;
				if (i <= j && j < i + len) {
					rep1(x, 1) {
						dp0[j + 1][x][1] += dp0[j][x][1];
						if (s[j] > c[j - i]) {
							(dp0[j + 1][x][1] += dp0[j][x][0]) %= mod;
						}
						else if (s[j] == c[j - i]) {
							(dp0[j + 1][x][0] += dp0[j][x][0]) %= mod;
						}
					}
				}
				else {
					(dp0[j + 1][0][1] += dp0[j][0][1]) %= mod;
					(dp0[j + 1][1][1] += dp0[j][0][1]*9) %= mod;
					(dp0[j + 1][1][1] += dp0[j][1][1] * 10) %= mod;
					//dp[j + 1][1] = dp[j][1] * 10 % mod;
					int t = s[j] - '0';
					if (t > 0) {
						//add 0
						rep(x, 2) {
							(dp0[j + 1][x][1] += dp0[j][x][0]) %= mod;
						}
					}
					if (t > 1) {
						//add nonzero
						rep(x, 2) {
							(dp0[j + 1][1][1] += dp0[j][x][0] * (t - 1)) %= mod;
						}
					}
					//add s[i]
					if (t > 0) {
						rep(x, 2) {
							(dp0[j + 1][1][0] += dp0[j][x][0]) %= mod;
						}
					}
					else {
						rep(x, 2) {
							(dp0[j + 1][x][0] += dp0[j][x][0]) %= mod;

						}
					}
				}
			}
			//cout << dp0[l][1][0] + dp0[l][1][1] << endl;
			ret += dp0[l][1][0] + dp0[l][1][1];
			while (ret >= mod)ret -= mod;
		}


		return ret;
	}
	for (int i = 0; i < l - len + 1; i++) {
		dp[0][0] = 1; dp[0][1] = 0;
		rep(j, l) {
			dp[j + 1][0] = dp[j + 1][1] = 0;
			if (i <= j && j < i + len) {
				dp[j + 1][1] = dp[j][1];
				if (s[j] > c[j-i]) {
					(dp[j + 1][1] += dp[j][0]) %= mod;
				}
				else if (s[j] == c[j - i]) {
					(dp[j + 1][0] += dp[j][0]) %= mod;
				}
			}
			else {
				dp[j + 1][1] = dp[j][1] * 10 % mod;
				int t = s[j] - '0';
				if(t>0)dp[j + 1][1] = (dp[j + 1][1] + dp[j][0] * t) % mod;
				dp[j + 1][0] = dp[j][0];
			}
		}
		//cout << dp[l][0] + dp[l][1] << endl;
		ret += dp[l][0] + dp[l][1];
		while (ret >= mod)ret -= mod;
	}
	return ret;
}
ll calc(ll le, ll ri, ll mid) {
	string ori = to_string(mid);
	int l = ori.length();
	ll ret = 0;
	for (int i = le; i <= ri; i++) {
		string s = to_string(i);
		int len = s.length();
		rep(j, len-l+1) {
			string u = s.substr(j, l);
			if (u == ori)ret++;
		}
	}
	return ret;
}
void solve() {
	//cout << calc(0, 9999, 0) << endl;
	string a, b; cin >> a >> b >> c;
	ll ans = calc(b) - calc(a);
	//cout << calc(a) << endl;
	//cout << calc(b) << endl;
	int len = c.length();
	rep(i, a.length()) {
		if (i + len <= a.length()) {
			string t = a.substr(i, len);
			if (t == c)ans++;
		}
	}
	ans = (ans%mod + mod) % mod;
	cout << ans << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}

