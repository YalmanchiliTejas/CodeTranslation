#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl ;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;

#define rep(i,N) for(int i=0; i < (int)N; i++)
#define all(v) (v).begin(),(v).end()

const ll INF = 1e18;

int main(){
	int n; cin >> n;
	vl a(n); rep(i,n) cin >> a[i];
	vector<vector<vl>> dp(n+1, vector<vl>(2, vl(3, -INF)));
	dp[0][1][0] = 0;

	rep(i,n)rep(j,2)rep(k,3){
		if(k+j<3) dp[i+1][1][k+j] = max(dp[i][j][k], dp[i+1][1][k+j]);
		if(j){
			dp[i+1][0][k] = max(dp[i][j][k]+a[i], dp[i+1][0][k]);	
		}
	}
	
	if(n%2) cout << max(dp[n][1][1], dp[n][0][2]);
	else cout << max(dp[n][0][1], dp[n][1][0]); 
}