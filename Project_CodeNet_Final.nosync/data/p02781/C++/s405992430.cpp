#include <bits/stdc++.h>
using namespace std;
#define forloop(n) for(int i = 0; i < n; i++)
#define ll long long
#define mod 1000000007
/*long long exp(long long taban, long long us) {
    long long carpan = taban;
    long long temp = us;
    long long res = 1;
    for(int i = 0;;i++){
        if(temp % 2) res = (res*carpan) % mod;
        temp /= 2;
        carpan = (carpan*carpan) % mod;
        if(temp == 0) break;
    }
    return res;
}
ll ebob(ll a, ll b){
	if(!a)return b;
	return ebob(b%a, a);
}
ll ekok(ll a, ll b){
	return (((a*b)%mod)*(exp(ebob(a,b), (ll)mod-2))) % mod;
}*/
/*void set_levels(int cur, int dont){
	level[cur] = level[dont] + 1;
	parent[cur] = dont;
	for(int i = 0; i < vec[cur].size(); i++){
		if(vec[cur][i] != dont) set_levels(vec[cur][i], cur);
	}
}*/
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string n; int k; cin>>n>>k;
	ll dp[n.length()][k+1][2] = {};
	for(int i = 0; i < n.length(); i++){
		if(i == 0){
			dp[i][0][0]++;
			for(int u = 1; u < n[0] - '0'; u++){
				dp[i][1][0]++;
			}
			dp[i][1][1]++;
			continue;
		}
		//dp[i][0][0] = dp[i-1][0][0] + dp[i-1][0][1];
		for(int u = 0; u < n[i] - '0'; u++){
			if(!u){
				for(int j = 0; j <= k; j++){
					dp[i][j][0] += dp[i-1][j][1];
				}
			}else
			for(int j = 1; j <= k; j++){
				dp[i][j][0] += dp[i-1][j-1][1]; 
			}
		}
		for(int j = 0; j <= k; j++){
			dp[i][j][0] += dp[i-1][j][0];
		}
		for(int u = 1; u <= 9; u++){
			for(int j = 1; j <= k; j++){
				dp[i][j][0] += dp[i-1][j-1][0];
			}
		}
		if(n[i] - '0'){
			for(int j = 1; j <= k; j++){
				dp[i][j][1] = dp[i-1][j-1][1];
			}
		}else{
			for(int j = 0; j <= k; j++)
				dp[i][j][1] = dp[i-1][j][1];
		}
	}
	cout<<dp[n.length()-1][k][0] + dp[n.length()-1][k][1];
}
