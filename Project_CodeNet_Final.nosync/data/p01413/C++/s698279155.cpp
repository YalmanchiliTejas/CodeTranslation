#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#define llint long long
#define inf 1e18

using namespace std;

llint N, M, W, T;
map<string, int> mp;
llint V[10], P[10];
llint X[10], Y[10];
llint Q[10][10];

llint dist[10][10];
llint cost[150];
llint dp[150][10];
llint dp2[10][10005];
llint gain[150];
llint dp3[10005];


int main(void)
{
	cin >> N >> M >> W >> T;
	string s;
	for(int i = 1; i <= M; i++){
		cin >> s >> V[i] >> P[i];
		mp[s] = i;
	}
	int L, q;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			Q[i][j] = inf;
		}
	}
	for(int i = 1; i <= N; i++){
		cin >> L >> X[i] >> Y[i];
		for(int j = 1; j <= L; j++){
			cin >> s >> q;
			Q[i][mp[s]] = q;
		}
	}
	
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= N; j++){
			dist[i][j] = abs(X[i]-X[j]) + abs(Y[i]-Y[j]);
		}
	}
	
	llint S = 1 << N;
	for(int i = 0; i < S; i++){
		for(int j = 0; j <= N; j++){
			dp[i][j] = inf;
		}
	}
	dp[0][0] = 0;
	for(int i = 0; i < S; i++){
		for(int j = 0; j <= N; j++){
			for(int k = 1; k <= N; k++){
				if(i & (1<<(k-1))) continue;
				dp[i|(1<<(k-1))][k] = min(dp[i|(1<<(k-1))][k], dp[i][j] + dist[j][k]);
			}
		}
	}
	for(int i = 0; i < S; i++){
		cost[i] = inf;
		for(int j = 0; j <= N; j++){
			cost[i] = min(cost[i], dp[i][j] + dist[0][j]);
		}
	}
	
	llint profit[10];
	for(int s = 0; s < S; s++){
		for(int i = 1; i <= M; i++) profit[i] = 0;
		for(int i = 1; i <= N; i++){
			if( (s & (1<<(i-1))) == 0 ) continue;
			for(int j = 1; j <= M; j++){
				profit[j] = max(profit[j], P[j] - Q[i][j]);
			}
		}
		
		for(int i = 0; i <= N; i++){
			for(int j = 0; j <= W; j++){
				dp2[i][j] = -inf;
			}
		}
		dp2[0][0] = 0;
		for(int i = 1; i <= M; i++){
			for(int j = 0; j <= W; j++){
				dp2[i][j] = dp2[i-1][j];
				if(j >= V[i]) dp2[i][j] = max(dp2[i][j], dp2[i][j-V[i]] + profit[i]) ; 
			}
		}
		
		gain[s] = 0;
		for(int j = 0; j <= W; j++){
			gain[s] = max(gain[s], dp2[M][j]);
		}
	}
	
	for(int i = 0; i <= T; i++){
		for(int j = 0; j < S; j++){
			if(i+cost[j] > T) continue;
			dp3[i+cost[j]] = max(dp3[i+cost[j]], dp3[i] + gain[j]);
		}
	}
	
	llint ans = 0;
	for(int i = 0; i <= T; i++) ans = max(ans, dp3[i]);
	cout << ans << endl;
	
	return 0;
}
