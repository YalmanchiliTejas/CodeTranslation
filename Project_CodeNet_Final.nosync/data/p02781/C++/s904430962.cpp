// Copyright 2020 yaito3014
#include <bits/stdc++.h>
using namespace std;

int main(){
	string N;
	int K;
	cin >> N >> K;
	int len = N.length();
	// dp[i][j][smaller]
	vector<vector<array<int,2>>> dp(len+1,vector<array<int,2>>(K+1));
	for(auto&v:dp)for(auto&w:v)w.fill(0);
	dp[0][0][0] = 1;
	for(int i = 0; i < len; ++i){
		for(int j = 0; j <= K; ++j){
			for(auto smaller : { true, false }){
				int k_n = smaller?9:N[i]-'0';
				for(int k = 0; k <= k_n; ++k){
					if(k!=0&&j==K)continue;
					dp[i+1][j+(k==0?0:1)][smaller||k<N[i]-'0']
						+= dp[i][j][smaller];
				}
			}
		}
	}
	cout << dp[len][K][0] + dp[len][K][1] << endl;
}
