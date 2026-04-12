#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define inside sl<=l&&r<=sr
#define outside r<sl||sr<l
#define INF 1000000009
#define mod 1000000007
using namespace std;
typedef long long ll;

string s;
int d;

ll dp[102][10005][2];

int main(){
	//freopen("stl.gir", "r", stdin);
	
	cin >> s >> d;
	for (int i = 0; i < s.size(); i++) s[i] -= '0';
	for (int i = s.size(); i >= 0; i--){
		for (int sum = 0; sum < d; sum++){
			if (i == s.size()){
				if (sum == 0) dp[sum][i][0] = dp[sum][i][1] = 1;
				else dp[sum][i][0] = dp[sum][i][1] = 0;
			} else {
				// free
				dp[sum][i][1] = 0;
				for (int k = 0; k < 10; k++){
					dp[sum][i][1] += dp[(sum+k)%d][i+1][1];
					dp[sum][i][1] %= mod;
				}
				
				// free degil
				dp[sum][i][0] = 0;
				//cout << "top: " << sum << ", " << i << ", " << 0 << endl;
				for (int k = 0; k < s[i]; k++){
					//cout << "ekle: " << "dp[" << (sum+k)%d << ", " << i+1 << ", " << 1 << ": " << dp[(sum+k)%d][i+1][1] << endl;
 					dp[sum][i][0] += dp[(sum+k)%d][i+1][1];
					dp[sum][i][0] %= mod;
				}
				//cout << "ekle: " << "dp[" << (sum+s[i])%d << ", " << i+1 << ", " << 0 << ": "<<  dp[(sum+s[i])%d][i+1][0] << endl;
				dp[sum][i][0] += dp[(sum+s[i])%d][i+1][0];
				dp[sum][i][0] %= mod;
			}
		}
	}
	
	ll ans = dp[0][0][0]-1;
	ans = ((ans%mod)+mod)%mod;
	cout << ans << endl;
	
}