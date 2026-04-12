#include<iostream>
#include<algorithm>
using namespace::std;
#define int long long int 
#define MOD 1000000007LL

int dp[10005][100][2];

main(){
	ios_base::sync_with_stdio(0);
	string s;
	int d;
	cin>>s>>d;
	reverse(s.begin(),s.end());
	for(int i=0;i<s.length();i++)
		for(int m=0;m<d;m++){
			dp[i][m][1]=(i?dp[i-1][(m+s[i]-'0')%d][1]:((m+s[i]-'0')%d)==0);
			for(int k=0;k<=9;k++){
				dp[i][m][0]=(dp[i][m][0]+(i?dp[i-1][(m+k)%d][0]:((m+k)%d)==0))%MOD;
				if(k<s[i]-'0')
					dp[i][m][1]=(dp[i][m][1]+(i?dp[i-1][(m+k)%d][0]:((m+k)%d)==0))%MOD;
			}
		}
	// for(int j=0;j<2;cout<<'\n',j++)
	// 	for(int m=d-1;m>-1;cout<<'\n',m--)
	// 		for(int i=0;i<s.length();i++)
	// 			cout<<dp[i][m][j]<<' ';
	cout<<(dp[s.length()-1][0][1]-1+MOD)%MOD<<'\n';
}