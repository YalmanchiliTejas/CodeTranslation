#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
string n;
int k;
ll dp[110][4][2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cin>>k;
	dp[0][0][1]=1;
	for(int i=0;i<n.length();i++){
		for(int j=0;j<=k;j++){
			if(n[i]=='0'){
				dp[i+1][j][1]+=dp[i][j][1];
			}else{
				dp[i+1][j][0]+=dp[i][j][1];
			}
			dp[i+1][j][0]+=dp[i][j][0];
			for(int l=1;l<10;l++){
				if(j>0){
					dp[i+1][j][0]+=dp[i][j-1][0];
					if(l<(n[i]-'0')){
						dp[i+1][j][0]+=dp[i][j-1][1];
					}else if(l==(n[i]-'0')){
						dp[i+1][j][1]+=dp[i][j-1][1];
					}
				}
			}
		}
	}
	cout<<dp[n.length()][k][0]+dp[n.length()][k][1]<<endl;
}
