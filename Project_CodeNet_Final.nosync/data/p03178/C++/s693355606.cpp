# include <bits/stdc++.h>
using namespace std;
# define MOD 1000000007
typedef long long ll;
int dp[10000][101][2];
int D, n;
string K;
int solve(int index, int sum, int tight){
    if(dp[index][sum][tight] != -1) return dp[index][sum][tight];
    int ans = 0;
    int limit = 9;
    if(tight) limit = K[index] - '0';
    if(index == n-1){
        for(int i=0;i<=limit;i++){
            if(i%D == sum){
                ans++;
            }
        }
        return ans;
    }
    for(int i=0;i<=limit;i++){
        if(tight == 1 and i == limit) ans = (ans + solve(index + 1, (D + sum - i%D)%D, 1))%MOD;
        else ans = (ans + solve(index + 1, (D + sum - i%D)%D, 0))%MOD;
    }
    return dp[index][sum][tight] = ans;
}
int main(){
	cin>>K>>D;
	n = K.length(); 
	memset(dp, -1, sizeof(dp));
	int ans = (MOD + solve(0, 0, 1) - 1)%MOD; // for 0%D
	cout<<ans;
	return 0;
}