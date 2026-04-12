#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353
#define PI 3.141592653

int main(){
	ll n, x, ans; cin >> n;
	if (n%2==0){
		vector<ll> a(n/2+1);
		vector<ll> bl(n/2+1);
		vector<ll> b(n/2+1);
		REP(i,n){
			cin >> x;
			if (i%2==0) a[i/2+1] = a[i/2]+x;
			else bl[i/2+1] = bl[i/2]+x;
		}
		REP(i,n/2+1) b[i] = bl[n/2]-bl[i];
		ans = a[0]+b[0];
		FOR(i,1,n/2){
			ans = max(ans, a[i]+b[i]);
		}
		cout << ans << endl;
	}
	else{
		vector<ll> a(n);
		REP(i,n) cin >> a[i];
		vector<vector<ll>> dp(n/2,vector<ll>(2));
		dp[0][0] = a[0];
		dp[0][1] = a[1];
		FOR(i,1,n/2-1){
			dp[i][0] = dp[i-1][0]+a[2*i];
			dp[i][1] = max(dp[i-1][0],dp[i-1][1])+a[2*i+1];
		}
		vector<ll> evenl(n/2+1);
		FOR(i,1,n/2) evenl[0] += a[2*i];
		FOR(i,1,n/2) evenl[i] = evenl[i-1]-a[2*i];
		ans = evenl[0];
		FOR(i,2,n/2+1){
			ll maxdp = max(dp[i-2][0], dp[i-2][1]);
			ans = max(ans, maxdp+evenl[i-1]);
		}
		cout << ans << endl;
	}
}