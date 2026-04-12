#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007LL

long long dp[10010][110][2];

int main(){
	string K;
	int D;
	cin >> K >> D;
	
	dp[0][0][0]=1;
	for(int i=0;i<K.size();i++)for(int j=0;j<D;j++){
		int k=K[i]-'0';
		for(int x=0;x<10;x++){
			if(x==k)dp[i+1][(j+x)%D][0]+=dp[i][j][0];
			if(x<k)dp[i+1][(j+x)%D][1]+=dp[i][j][0];
			dp[i+1][(j+x)%D][1]+=dp[i][j][1];
			dp[i+1][(j+x)%D][0]%=MOD;
			dp[i+1][(j+x)%D][1]%=MOD;
		}
	}
	/*for(int i=0;i<=K.size();i++){
		for(int j=0;j<D;j++)cout << dp[i][j][0] << " ";
		cout << endl;
	}
	for(int i=0;i<=K.size();i++){
		for(int j=0;j<D;j++)cout << dp[i][j][1] << " ";
		cout << endl;
	}*/
	cout << (dp[K.size()][0][0]+dp[K.size()][0][1]+MOD-1)%MOD << endl;
	return 0;
}