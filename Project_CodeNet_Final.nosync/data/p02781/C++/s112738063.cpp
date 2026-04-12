#include<iostream>
using namespace std;
string N;long K,dp[111][2][4],i,j,k,l,r,c,M;
int main(){
	cin>>N>>K;
	M=N.size();
	dp[0][0][0]=1;
	for(i=0;i<N.size();i++){
		for(j=0;j<2;j++){
			r=j?9:N[i]-'0';
			for(k=0;k<=K;k++){
				for(l=0;l<=r;l++){
					c=k+!!l;
					if(c<=K)dp[i+1][j||l<r][c]+=dp[i][j][k];
				}
			}
		}
	}
	cout<<dp[M][0][K]+dp[M][1][K]<<endl;
}
