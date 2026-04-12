#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int dp[102][4][2];

int main(){
	string N;
	int K;
	cin >> N >> K;
	int ketasu = N.size();
	dp[0][0][0] = 1;//0桁の/非０数が０個の/不確定に１
	rep(i, ketasu)rep(j, K+1)rep(k, 2){
		int a = N[i] - '0';
		int ni = i+1;
		rep(d, 10){
			int nj = j, nk = k;
			if(d != 0) nj++;
			if(nj > K) continue;
			if(nk == 0){
				if(d > a) continue;
				if(d < a) nk = 1;
			}
			dp[ni][nj][nk] += dp[i][j][k];
		}
	}
	cout << dp[ketasu][K][0] + dp[ketasu][K][1] << endl;
	
	return 0;
}