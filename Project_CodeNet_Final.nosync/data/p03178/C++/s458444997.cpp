#include<bits/stdc++.h>
using namespace std; 
#define mo 1000000007

string s; int d; int dp[10001][101][2];
int main()
{
	cin>>s>>d; 
	int l = s.size();
	for(int i = 0; i<s[0]-'0'; i++)
	{
		dp[0][i%d][0]++;
	}
	dp[0][(s[0]-'0')%d][1]++; 
	for(int i = 1 ; i<l; i++)
	{
	 int v = s[i]-'0'; 
	 for(int j = 0 ; j<d; j++)
	 {
	 	for(int k = 0 ;k<=9; k++)
	 	{
	 		if(k==v)
	 		dp[i][(j+k)%d][1] = (dp[i][(j+k)%d][1]+ dp[i-1][j][1])%mo;
	 		else if(k<v)
	 		dp[i][(j+k)%d][0]= (dp[i][(j+k)%d][0]+ dp[i-1][j][1])%mo;
	 		
	 		dp[i][(j+k)%d][0] = (dp[i][(j+k)%d][0]+ dp[i-1][j][0])%mo;
		 }
	 }
	}

	cout<<((dp[l-1][0][0]+dp[l-1][0][1]-1)%mo+mo)%mo; 
}
