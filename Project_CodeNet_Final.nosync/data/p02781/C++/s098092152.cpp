#include <bits/stdc++.h>
#define LL long long
using namespace std;
string N; int l,K; LL ans;
LL dp[105][5][2];
int main(){
	int i,j,k,t;
	cin >> N >> K; l = N.size();
	for (i = 0; i < l; ++i){
		for (j = 0; j <= 9; ++j){
			if (j){
				if (i==0){
					if (j < N[0]-'0') ++dp[i][1][1];
					else if (j==N[0]-'0')++dp[i][1][0];
				}
				else ++dp[i][1][1];
			}
			if (i>0){
				for (k = 1; k <= K; ++k)
				for (t = 0; t <= 1; ++t){
					//dp[i-1][k][t];
					if (t==1){
						if (j) dp[i][k+1][t] += dp[i-1][k][t];
						else dp[i][k][t] += dp[i-1][k][t];
					}
					if (t==0){
						if (j>N[i]-'0') continue;
						if (j==N[i]-'0'){
							if (j) dp[i][k+1][t] += dp[i-1][k][t];
							else dp[i][k][t] += dp[i-1][k][t];
						}
						if (j<N[i]-'0'){
							if (j) dp[i][k+1][1] += dp[i-1][k][t];
							else dp[i][k][1] += dp[i-1][k][t];
						}
					}
				}
			}
		}
		if (i==l-1){
			for (k = K; k <= K; ++k)
			for (t = 0; t <= 1; ++t) ans += dp[i][k][t];
		}
	}
	cout<<ans<<endl;
    return 0;
}