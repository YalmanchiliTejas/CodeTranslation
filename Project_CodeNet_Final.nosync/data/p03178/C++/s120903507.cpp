#include<bits/stdc++.h>
using namespace std;
int dp[10005][103][7];
const int MOD=1e9+7;
string s;
int d;
inline int real(int x){
	x%=d;
	if(x<0)x+=d;
	return x;
}
int main(){
	
	cin>>s>>d;
	int sz=(int)s.size();
	for(int i=0;i<=s[0]-'0'-1;i++) dp[0][i%d][0]++;
	dp[0][(s[0]-'0')%d][1]=1;
	for(register int i=1;i<sz;i++){
		for(int j=0;j<d;j++){
			for(int k=0;k<=9;k++){
				dp[i][j][0]+=dp[i-1][real(j-k)][0];
				if(k<s[i]-'0') dp[i][j][0]+=dp[i-1][real(j-k)][1];
//				cout<<k<<" "<<dp[i-1][real(j-k)][0]<<endl;
				if(dp[i][j][0]>=MOD) dp[i][j][0]-=MOD;
			}
			dp[i][j][1]=dp[i-1][real(j-s[i]+'0')][1];
//			cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl; 
		}
	}
	cout<<(dp[sz-1][0][0]+dp[sz-1][0][1]-1+MOD)%MOD;
}