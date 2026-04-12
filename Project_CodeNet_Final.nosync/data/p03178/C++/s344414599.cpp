#include <iostream>
#include <string> 
#include <cstring>
using namespace std;

const int P=1e9+7;

int main(){
	string K;
	long long d,dgt;
	cin>>K>>d;
	dgt=K.length();

	long long dp[dgt][d];
	memset(dp,0,sizeof(dp));

	for(char i='0';i<K[0];i++){
		dp[0][(i-'0')%d]+= 1;
	}
	long long edge = (K[0]-'0')%d;

	for(int i=1;i<dgt;i++){
		
		for(int j=0;j<d;j++){
			for(int k=0;k<10;k++){
				dp[i][(j+k)%d] = (dp[i-1][j] + dp[i][(j+k)%d])%P;
			} 
		}

		for(char k='0';k<K[i];k++){
			dp[i][(edge+k-'0')%d] = (dp[i][(edge+k-'0')%d] + 1)%P;
		}
		edge = (edge+K[i]-'0')%d;
	}
/*
	for(int i=0;i<d;i++){
		for(int j=0;j<dgt;j++){
			cout<<dp[j][i]<<"\t";
		}
		cout<<"\n";
	}
*/
	long long ans = dp[dgt-1][0]-1+(edge==0);
	ans = (ans+P)%P;
	cout<<ans<<endl;
}
