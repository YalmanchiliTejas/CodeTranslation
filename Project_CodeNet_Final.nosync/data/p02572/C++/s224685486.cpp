#include <bits/stdc++.h>

using namespace std;

#define FOR(i, n) for(int i = 0; i < (int) n; i++)
#define PB push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

long double EPS = 1e-9;

const int MOD = 1e9+7;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	vi v(n); FOR(i, n) cin >> v[i];

	vi dp(v);
	for(int i = n-2; i >= 0; i--)
		dp[i] = (dp[i] + dp[i+1]) % MOD;

	ll ans = 0;
	FOR(i, n-1){
		int add = 1LL * v[i] * dp[i+1] % MOD;
		ans = (ans + add) % MOD;
	}

	cout << ans << '\n';

	return 0;
}
