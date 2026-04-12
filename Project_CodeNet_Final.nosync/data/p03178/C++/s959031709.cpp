#include<bits/stdc++.h>
using namespace std;
//here i1 is showing whether some digit is smaller or not encountered till date
//if smaller or equal digit then no restriction and if larger digit then smaller encountered should be true
int main()
{string s;
cin>>s;
int d;
cin>>d;
//cout<<s<<" s_d "<<d<<endl;
int mod=1e9+7;
int dp[d+1][2][s.length()+1];
for(int i=0;i<=d;i++)
{for(int j=0;j<=s.length();j++){
	dp[i][0][j]=0;
dp[i][1][j]=0;
}}
//cout<<dp[0][0][0]<<endl;
dp[0][0][0]=1;
//cout<<"pp "<<endl;
for(int k=1;k<=s.length();k++){

for(int i=0;i<d;i++)
{for(int j=0;j<=9;j++)
{//cout<<s[k]-'0'<<"pp "<<endl;
for(bool i1:{false,true})
{int x=s[k-1]-'0';
	if((j>(x)&&i1==true)||(j<=x)){
dp[(i+j)%d][i1||(j<x)][k]=(dp[(i+j)%d][i1||(j<x)][k]+dp[i][i1][k-1])%mod;
//cout<<dp[(i+j)%d][i1||(j<s[k]-'0')][k]<<" ll "<<endl;
		
	}
}}}}
int ans=(dp[0][false][s.length()]+dp[0][true][s.length()])%mod;
ans--;
if(ans<0)
ans+=mod;
cout<<(ans)<<endl;
return 0;}
