#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n, m, mod;
llint dp[205][105][1<<10];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> mod;
	
	llint S = 1<<m;
	vector<llint> uvec, dvec;
	
	dp[1][1][1] = 1;
	for(int i = 1; i < 2*n; i++){
		for(int j = 1; j <= n; j++){
			llint u = j, d = i-j, nk;
			for(int k = 0; k < S; k++){
				//cout << i << " " << j << " " << k << endl;
				uvec.clear(), dvec.clear();
				for(int l = 0; l < m; l++){
					if(k & (1<<l)){
						if(i-l >= 1) uvec.push_back(i-l);
					}else{
						if(i-l >= 1) dvec.push_back(i-l);
					}
				}
				uvec.push_back(1), dvec.push_back(1);
				
				if(u < n){
					if(i+1 - uvec.front() <= m){
						nk = ((k << 1) % (1<<m)) | 1;
						dp[i+1][j+1][nk] += dp[i][j][k];
						dp[i+1][j+1][nk] %= mod;
					}
				}
				//cout << d << " " << u << endl;
				if(d < u){
					//cout << "*" << i << " " << j << " " << k << endl;
					//for(int p = 0; p < dvec.size(); p++) cout << dvec[p] << " "; cout << endl;
					//for(int p = 0; p < uvec.size(); p++) cout << uvec[p] << " "; cout << endl;
					
					if(i+1 - dvec.front() <= m && u-d <= m && i+1 - uvec[u-d-1] <= m){
						nk = ((k << 1) % (1<<m));
						dp[i+1][j][nk] += dp[i][j][k];
						dp[i+1][j][nk] %= mod;
					}
				}
			}
		}
	}
	
	/*for(int i = 1; i <= 2*n; i++){
		for(int j = 0; j <= n; j++){
			for(int k = 0; k < S; k++){
				cout << dp[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}*/
	
	llint ans = 0;
	for(int i = 0; i < S; i++) ans += dp[2*n][n][i], ans %= mod;
	cout << ans << endl;
	
	
	
	return 0;
}
