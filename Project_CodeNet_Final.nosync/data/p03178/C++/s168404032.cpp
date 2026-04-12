#include<map>
#include<set>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<chrono>
#include<stack>
#include<fstream>
#include<list>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define SIZE(a) ll(a.size())
#define vll vector<ll> 
#define MEMSET(a, n, m) for(ll i=0;i<=n;i++) a[i] = m
#define BIT(n) (ll(1)<<n)
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end()) 
#define UNIQUE_ARRAY(a,x) unique(a + 1, a + x + 1) - a - 1
#define SORT(a,n) sort(a+1,a+n+1)
#define SORT_O(a,n,order) sort(a+1,a+n+1,order)
#define PER(i,y,x) for(ll i=y;i>=x;i--)
typedef long long ll;
using namespace std;


struct edge
{
	long long to; long long len;
	bool operator<(const edge& rhs) const {
		return len > rhs.len;
	}
};

string s;
ll t;

ll dp[100005][105] = {};
ll n;

ll const MOD = 1e9 + 7;
ll mod_p(ll x, ll y) {
	return (x + y + MOD) % MOD;
}

void fill_dp() {
	dp[0][0] = 1;
	REP(i, 1, n) {
		REP(j, 0, t - 1) {
			REP(k, 0, 9) {
				dp[i][j] = mod_p(dp[i][j], dp[i - 1][(j + 100 * t - k) % t]);
			}
		}
	}
}

ll f(string s, ll x, ll y) {
	if (x == n) {
		if (y == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		ll c = s[x] - '0';
		//cout << x + 1 << (y - c + 100 * t) % t << endl;
		ll cnt = f(s, x + 1, (y - c + 100 * t) % t);
		REP(i, 0, c - 1) {
			cnt = mod_p(cnt, dp[n - x - 1][(y - i + 100 * t) % t]);
		}
		return cnt;
	}
}

int main() {
	cin >> s >> t;
	n = s.size();
	fill_dp();
	cout << mod_p(MOD - 1, f(s, 0, 0)) << endl;
	/*
	REP(i, 0, n) {
	REP(j, 0, t) {
	cout << dp[i][j] << " ";
	}
	cout << endl;
	}
	*/
}
