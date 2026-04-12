#include <bits/stdc++.h>
using namespace std;

string k;
long long d, mod = 1e9+7, dp[2][100010][101], ans;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> k >> d;
	for(int i=0; i<k[0]-'0'; ++i) ++dp[0][0][i%d];
	dp[1][0][(k[0]-'0')%d] = 1;
	for(int i=1; i<k.size(); ++i){
		for(int j=0; j<10; ++j){
			for(int l=0; l<d; ++l){
				dp[0][i][(l+j)%d] += dp[0][i-1][l];
				dp[0][i][(l+j)%d] %= mod;
				if(j < k[i]-'0'){
					dp[0][i][(l+j)%d] += dp[1][i-1][l];
					dp[0][i][(l+j)%d] %= mod;
				}else if(j == k[i]-'0' && dp[1][i-1][l] == 1){
					dp[1][i][(l+j)%d] = 1;
				}
			}
		}
	}
	ans = (dp[0][k.size()-1][0] - 1 + dp[1][k.size()-1][0]) % mod;
	if(ans < 0) ans += mod;
	cout << ans << "\n";
}