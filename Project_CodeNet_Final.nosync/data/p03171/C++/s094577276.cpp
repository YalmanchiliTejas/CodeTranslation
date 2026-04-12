#include<iostream>
#include<vector>

using namespace std;

long long int dp[3001][3001][2];
long long int helper(vector<int>&game,int l,int r,int chance){
	if(dp[l][r][chance] > -1){
		return dp[l][r][chance];
	}
	if(l > r){
		return 0;
	}
	else{
		dp[l][r][chance] = (max(game[l]-helper(game,l+1,r,1-chance),game[r]-helper(game,l,r-1,1-chance))); 
		return dp[l][r][chance];
	}
}
int main(){
	int n;cin>>n;
	vector<int>game(n);
	for(int i=0;i<n;i++){
		cin>>game[i];
	}
	for(int i=0;i<3001;i++){
		for(int j=0;j<3001;j++){
			for(int k=0;k<2;k++){
				dp[i][j][k] = -1;
			}
		}
	}
	cout<<helper(game,0,n-1,0);
}
