#include <bits/stdc++.h>
////////////////////////////////////////////////////////////
#define all(x) (x).begin(), (x).end() 
const int inf = 1e9;
const long long INF=1e15;
#define endl '\n'
#define rep(i, n) for(int i=0;i<(n);++i)
#define repp(i, a, b) for(int i=(a);i<=(b);++i)
#define pb push_back
#define eb emplace_back
#define fastio ios::sync_with_stdio(false);cin.tie(0); //cout.tie(0);

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

ll mod = 998244353;
ll dp[3001][3];
// dp[sum][t]
// [t]
// [0] = only (L)
// [1] = (L, x, ..)
// [2] = (L, .x. ,  R)
int main() {
	int n, s; cin >> n >> s;
	vi a(n); rep(i, n) cin >> a[i];
	for(int i=0;i<n;i++) {
		dp[0][0]++; dp[0][0] %= mod;
		
		
		for(int j=s;~j;j--) {
			if(j + a[i] <= s)
				dp[j+a[i]][1] += dp[j][1], dp[j+a[i]][1] %= mod;
		}
		dp[a[i]][1] += dp[0][0]; dp[a[i]][1] %= mod;
		for(int j=s;~j;j--) {
			dp[j][2] += dp[j][1], dp[j][2] %= mod;
		}
	}
	cout << dp[s][2];
}