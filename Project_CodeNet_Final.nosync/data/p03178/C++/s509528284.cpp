#include"bits/stdc++.h"
using namespace std;
#define LL long long
#define PB push_back
#define MP make_pair

#define MOD 1000000007

string K;
int D;

LL dp[10001][100][2];
LL solve(int now, int sum, int giri){
	if(now == K.size()){
		if(sum == 0) return 1;
		else return 0;
	}
	if(dp[now][sum][giri] != -1) return dp[now][sum][giri];
	LL ret = 0;
	for(int i=0; i<10; i++){
		if(giri == 1 && K[now]-'0' < i) break;
		if(giri == 1 && K[now]-'0' == i) ret += solve(now+1, (sum+i)%D, 1);
		else ret += solve(now+1, (sum+i)%D, 0);
	}
	return dp[now][sum][giri] = ret % MOD;
}

int main(){
	cin >> K >> D;
	for(int i=0; i<K.size(); i++){
		for(int j=0; j<D; j++){
			for(int k=0; k<2; k++){
				dp[i][j][k] = -1;
			}
		}
	}
	cout << (solve(0, 0, 1) + MOD - 1) % MOD << endl;
}