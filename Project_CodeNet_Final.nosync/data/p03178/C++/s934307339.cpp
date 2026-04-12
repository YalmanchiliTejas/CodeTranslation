#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
const int MAXN=1e4+10;
const int MAXD=1e2+10;
const int MOD=1e9+7;
string num;
int n,d,sol;
int dp[MAXN][MAXD];
int dp2[MAXN][MAXD][2];
int add(int x,int y){
	return (x+y)%MOD;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>num>>d;
	n=num.length()-1;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=(i==1)?1:0;j<=9;j++){
			for(int k=0;k<d;k++){
				dp[i][(j+k)%d]=add(dp[i][(j+k)%d],dp[i-1][k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		sol=add(sol,dp[i][0]);
	}
	n++;
	dp2[0][0][1]=1;
	for(int i=1;i<=n;i++){
		int z=(int)num[i-1]-'0';
		for(int j=(i==1)?1:0;j<=9;j++){
			if(i==1&&j>z) break;
			for(int k=0;k<d;k++){
				if(j<z){
					dp2[i][(j+k)%d][0]=add(dp2[i][(j+k)%d][0],add(dp2[i-1][k][0],dp2[i-1][k][1]));
					//dp2[i][(j+k)%d][0]+=dp2[i-1][k][0]+dp2[i-1][k][1];
					//dp2[i][(j+k)%d][0]=add(dp2[i][(j+k)%d][0],dp2[i-1][k][1])
				}
				else if(j==z){
					dp2[i][(j+k)%d][0]=add(dp2[i][(j+k)%d][0],dp2[i-1][k][0]);
					dp2[i][(j+k)%d][1]=add(dp2[i][(j+k)%d][1],dp2[i-1][k][1]);
					//dp2[i][(j+k)%d][0]+=dp2[i-1][k][0];
					//dp2[i][(j+k)%d][1]+=dp2[i-1][k][1];
				}
				else{
					dp2[i][(j+k)%d][0]=add(dp2[i][(j+k)%d][0],dp2[i-1][k][0]);
					//dp2[i][(j+k)%d][0]+=dp2[i-1][k][0];
				}
				
				//dp[i][(j+k)%d]=add(dp[i][(j+k)%d],dp[i-1][k]);
			}
		}
	}
	sol=add(sol,add(dp2[n][0][0],dp2[n][0][1]));
	cout<<sol<<"\n";
	return 0;
}