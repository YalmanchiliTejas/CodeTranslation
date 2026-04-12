#include <bits/stdc++.h>

using namespace std;






string s;
long long int dp[10001][2][101];
int d;
long long int MOD = 1000000007;
long long int solve(int i,int pode,int resto){
	if(i == s.size() && resto == 0){
		return 1;
	}
	if(i == s.size()){
		return 0;
	}
	if(dp[i][pode][resto] != -1){
		return dp[i][pode][resto];
	}
	int num = s[i] - '0';
	if(pode == 1){
		num = 9;
	}
	int aux = pode;
	long long int  ans = 0;
	for(int j = num; j>= 0 ;j--){
		if(s[i] - '0' > j){
			aux = 1;
		}
		ans = (ans + solve(i+1,aux,(resto + j)%d))%MOD;
	}
	return dp[i][pode][resto] = ans ;
}

int main(){
	cin.tie();
	ios_base::sync_with_stdio(0);
	cin >> s;
	cin >> d;
	memset(dp,-1,sizeof dp);
	cout << (solve(0,0,0) - 1LL + MOD)%MOD<< endl;
	return 0;
}
