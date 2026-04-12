#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 998244353;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll n, s, a[5000], dp[5000];

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n >> s;
	zep(i, 0, n){
		cin >> a[i];
	}
	
	ll ans = 0;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	zep(i, 0, n){
		rrep(j, s, 0){
			if(a[i]+j <= s){
				dp[a[i]+j] += dp[j];
				dp[a[i]+j] %= MOD;
			}
		}
		dp[0]++;
		dp[0] %= MOD;
		
		ans += dp[s];
		ans %= MOD;
	}
	print(ans)
	return 0;
}