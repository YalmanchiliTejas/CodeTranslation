#include <bits/stdc++.h>
#define int long long
using namespace std;

int H[105];

int dp[105][105];
int all[105];

int mod = 1000000007;
long long qexp(long long b, long long p){
    long long res = 1;
    while(p){
        if(p&1) res = (res * b) % mod;
        b = (b * b) % mod;
        p >>= 1;
    }
    return res;
}

vector<int> dis = {1};
int get(int x){ return lower_bound(dis.begin(),dis.end(),x) - dis.begin(); }
void c(int &x){
	x %= mod;
	if(x < 0) x += mod;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> H[i];
		dis.push_back(H[i]);
	}

	sort(dis.begin(),dis.end());
	dis.erase(unique(dis.begin(), dis.end()), dis.end());
	int m = dis.size();
	
	all[0] = 1;
	
	for(int i = 1;i <= n;i++){
		if(H[i] > H[i-1]){			
			for(int j = m-1;j >= 0;j--){
				if(dis[j] >= H[i]) dp[i][j] = 0;
				else if(dis[j] >= H[i-1]){
					dp[i][j] = all[i-1] * (qexp(2, H[i] - dis[j]) - 1) * 2;
					c(dp[i][j]);
				}
				else{
					dp[i][j] = dp[i-1][j] * qexp(2,H[i] - H[i-1]);
					c(dp[i][j]);
					dp[i][j] += all[i-1] * (qexp(2, H[i] - H[i-1]) - 1) * 2;
					c(dp[i][j]);
				}
			}
			all[i] = all[i-1] * 2;
			c(all[i]);
		}
		else{
			for(int j = 0;j < m;j++){
				if(dis[j] >= H[i]) dp[i][j] = 0;
				else{
					dp[i][j] = dp[i-1][j] - dp[i-1][get(H[i])];
					c(dp[i][j]);
				}
			}
			all[i] = (all[i-1] + dp[i-1][get(H[i])]) * 2;
			c(all[i]);
		}
		
	}
	
	int ans = all[n] + dp[n][0];
	c(ans);
	
	cout << ans;
}

