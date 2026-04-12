#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint MOD = 1e9+7;
lint dp[110][110][2];

signed main(){
	string s; cin >> s;
	lint K; cin >> K;
	lint N = s.size();
	dp[0][0][0] = 1;
	for(lint i = 0; i < N; i++){
		for(lint j = 0; j < 100; j++){
			for(lint k = 0; k < 2; k++){
				if(k == 1){
					for(lint l = 0; l < 10; l++){
						dp[i + 1][j + (l != 0)][1] += dp[i][j][1];
					}
				}
				if(k == 0){
					lint lim = s[i] - '0';
					for(lint l = 0; l <= lim; l++){
						dp[i + 1][j + (l != 0)][l != lim] += dp[i][j][0];
					}
				}
			}
		}
	}
	cout << dp[N][K][0] + dp[N][K][1] << endl;
}