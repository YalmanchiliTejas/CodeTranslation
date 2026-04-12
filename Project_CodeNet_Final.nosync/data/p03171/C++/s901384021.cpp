#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll n, a[5000], dp[5000][5000], use[5000][5000];

ll fetch(ll qi, ll qj){
	if(use[qi][qj]){
		return dp[qi][qj];
	}
	use[qi][qj] = true;
	
	ll t = n-(qj-qi);
	if(t%2 == 0){
		return dp[qi][qj] = max(fetch(qi, qj-1)+a[qj-1], fetch(qi+1, qj)+a[qi]);
	}
	else{
		return dp[qi][qj] = min(fetch(qi, qj-1)-a[qj-1], fetch(qi+1, qj)-a[qi]);
	}
}

int main(){
	cin.tie(0); ios::sync_with_stdio(false);

	cin >> n;
	rep(i, 0, n){
		cin >> a[i];
	}
	memset(use, 0, sizeof(use));
	for(ll k = 0; k <= n; k++){
		dp[k][k] = 0;
		use[k][k] = true;
	}
	
	print(fetch(0, n))
	
	return 0;
}