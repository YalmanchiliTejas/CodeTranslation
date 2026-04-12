#include <bits/stdc++.h>

using namespace std;
//#define int long long
const int mod = 1e9+7;

int dp[10003][100][2];

int main(){
	string K;
	int D; 
	cin >> K >> D;
	int n = K.length();
	
	for(int i = 0; i < K[0] - '0'; i++){
		dp[0][i%D][0]++;
	}
	dp[0][(K[0]-'0')%D ][1]++;
	
	for(int i = 1; i < n; i++){
		for(int j = 0; j < D; j++){
			for(int k = 0; k < 2; k++){
				int up = 9;
				if(k) up = K[i] - '0';
				for(int d = 0; d <= up; d++){
					int ns = k & (d==up);
					dp[i][(j+d)%D][ns]+=dp[i-1][j][k];
					dp[i][(j+d)%D][ns]%=mod;
				}
			}
		}
	}
	int res = 1ll*(dp[n-1][0][0] + dp[n-1][0][1]-1+mod) % mod;
	cout << res << "\n";
	return 0;
}
