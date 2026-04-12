#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;


//int dp[105][4][2];

int main(void){
	string N;
	int K;
	cin >> N;
	cin >> K;
	int L = N.size();
	int dp[105][4][2];
	//dp[0][0][0] = 1;
	for(int i = 0; i < 105; ++i){
		for(int j = 0; j < 4; ++j){
			for(int k = 0; k < 2; ++k){
				dp[i][j][k] = 0;
			}
		}
	}
	dp[0][0][0] = 1;
	for(int i = 0; i < L; ++i){
		for(int j = 0;j < 4;++j){
			for(int k = 0;k < 2; ++k){
				int now = N[i] - '0';
				for(int l = 0; l < 10; ++l){
					int ni = i +1, nj = j, nk = k;
					if(l != 0){
						nj++;
					}
					if(nj > K){
						continue;
					}
					if(k == 0){
						if(l > now){
							continue;
						}
						if(l < now){
							nk = 1;
						}
					}
						dp[ni][nj][nk] += dp[i][j][k];
				}
			}
		}
	}
	int ans = dp[L][K][0] + dp[L][K][1];
	//cout << dp[L][K][0] << ' ' << dp[L][K][1] << endl;
	cout << ans << endl;
	return 0;
}

