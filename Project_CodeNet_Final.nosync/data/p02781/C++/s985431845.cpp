#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = (int)1e9;
const int MOD = (int)1e9 + 7;

string N;
int K;
ll dp[200][4][2];

int main(void){
	cin >> N >> K;
	int len = N.size();

	dp[0][0][0] = 1;
	for(int i = 0; i < len; i++){
		for(int j = 0; j <= K; j++){
			if(j <= K-1) dp[i+1][j+1][1] += dp[i][j][1] * 9;
			if(j <= K-1 and N[i] >= '1') dp[i+1][j+1][1] += (dp[i][j][0] * (N[i] - '0' - 1));
			if(j <= K-1 and N[i] >= '1') dp[i+1][j+1][0] += dp[i][j][0];
			
			if(N[i] == '0'){
				dp[i+1][j][0] += dp[i][j][0];
				dp[i+1][j][1] += dp[i][j][1];
			}else{
				dp[i+1][j][1] += dp[i][j][1] + dp[i][j][0];
			}
		}
	}

	cout << dp[len][K][0] + dp[len][K][1] << '\n';

	return 0;
}