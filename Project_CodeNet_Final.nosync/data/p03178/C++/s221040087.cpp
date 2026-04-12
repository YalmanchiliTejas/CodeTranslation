#include<bits/stdc++.h>
#define rep(i,n)        for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const int Mod = 1000000007;
ll dp[2][2][110];
string s;
int d;
signed main(){
	ios::sync_with_stdio(false);
	cin >> s >> d;
	for(int i = 0; i < (s[0] - '0'); i++) dp[0][0][i % d]++;
	dp[1][0][(s[0] - '0') % d]++;
	for(int i = 1; i < s.size(); i++){
		int now = i & 1, prev = (i - 1) & 1;
		rep(j, d) dp[0][now][j] = dp[1][now][j] = 0;
		rep(j, d){
			dp[1][now][(j + (s[i] - '0')) % d] += dp[1][prev][j];
			dp[1][now][(j + (s[i] - '0')) % d] %= Mod;
			for(int k = 0; k < 10; k++){
				dp[0][now][(j + k) % d] += dp[0][prev][j];
				dp[0][now][(j + k) % d] %= Mod;
				if(k < (s[i] - '0')){
					dp[0][now][(j + k) % d] += dp[1][prev][j]; 
					dp[0][now][(j + k) % d] %= Mod;
				}
			}
		}
	}
	int a = (s.size() - 1) & 1;
	cout << ((dp[0][a][0] + dp[1][a][0] - 1) % Mod + Mod) % Mod << endl;
	return 0;
}