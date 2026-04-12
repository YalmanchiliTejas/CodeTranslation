#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
using namespace std;
#define ll long long
int main(){
	string N;
	int K;
	cin >> N >> K;
	int i,j,k;
	ll dp[N.size()][2][4];
	int tmp=int(N[0])-48;
	for(k=0;k<=3;k++){
		dp[0][0][k]=0;
		dp[0][1][k]=0;
	}
		dp[0][1][0]=1;
		dp[0][0][1]=1;
		dp[0][1][1]=tmp-1;
	for(i=1;i<N.size();i++){
		tmp=int(N[i])-48;
		dp[i][0][0]=0;
		dp[i][1][0]=1;
		for(k=1;k<4;k++){
			if(tmp==0)dp[i][0][k]=dp[i-1][0][k];else dp[i][0][k]=dp[i-1][0][k-1];
			if(tmp==0)dp[i][1][k]=9*dp[i-1][1][k-1]+dp[i-1][1][k];
			else dp[i][1][k]=9*dp[i-1][1][k-1]+dp[i-1][1][k]+(tmp-1)*dp[i-1][0][k-1]+dp[i-1][0][k];
		}
	}
	cout << dp[N.size()-1][0][K]+dp[N.size()-1][1][K];
	return 0;
}
