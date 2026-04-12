#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;

ll mod=1e9+7;
ll dp[10100][2][110];

int main(){
	string s; cin >> s;
	int d; cin >> d;
	int n=s.size();
	dp[0][0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<d;k++){
				if(dp[i][j][k]==0)continue;
				if(j==1){
					for(int l=0;l<=9;l++){
						(dp[i+1][j][(k+l)%d]+=dp[i][j][k])%=mod;
					}
				}
				else{
					(dp[i+1][0][(k+(s[i]-'0'))%d]+=dp[i][j][k])%=mod;
					for(int l=0;l<(s[i]-'0');l++){
						(dp[i+1][1][(k+l)%d]+=dp[i][j][k])%=mod;
					}
				}
			}
		}
	}
	cout << (dp[n][0][0]+dp[n][1][0]-1+mod)%mod << endl;
	return 0;
}