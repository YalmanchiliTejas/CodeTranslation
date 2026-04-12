#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const ll MOD = 998244353;
const ll INF = 2147483647;
const ll LINF = 9223372036854775807;
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

int main(){
	int n, s; cin >> n >> s;
	VI a(n); REP(i,n) cin >> a[i];
	ll dp[3001][3001][3]={0};
	REP(i,n) dp[i][0][0]=1;
	REP(i,n){
		REP(j,s+1){
			dp[i+1][j][1]+=dp[i][j][1]+dp[i][j][0];
			if(j-a[i]>=0) 
				dp[i+1][j][1]+=dp[i][j-a[i]][1]+dp[i][j-a[i]][0];
			dp[i+1][j][2]+=dp[i][j][2]+dp[i+1][j][1];
			dp[i+1][j][1]%=MOD;
			dp[i+1][j][2]%=MOD;
		}
	}
	cout << dp[n][s][2] << endl;
	return 0;
}