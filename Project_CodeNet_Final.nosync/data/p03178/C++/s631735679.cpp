#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define ip pair<ll,ll>
// const ll INF = 1000000000000000000;
const ll MOD = 1000000007;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	string k;
	cin>>k;
	int d;
	cin>>d;
	int n = k.length();
	// dp[m][r] - number of m digit numbers with 0-9 with sum r mod d.
	ll dp[n][d];
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	for(int i=1;i<n;i++){
		for(int j=0;j<d;j++){
			dp[i][j] = 0;
			for(int k=0;k<10;k++)
				dp[i][j] += dp[i-1][(j+d-k%d)%d];
			dp[i][j] %= MOD;
		}
	}

	ll ans = 0;
	ll cur = 0;
	for(int i=0;i<n;i++){
		int idx = (int)(k[i]-'0');
		for(int j=0;j<idx;j++){
			ans += dp[n-1-i][(d-cur)%d];
			++cur;
			if(cur >= d)
				cur -= d;
		}
		ans %= MOD;
	}

	if(cur%d != 0)
		ans = (ans+MOD-1)%MOD;

	cout<<ans%MOD<<endl;
}
