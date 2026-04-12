#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
string s;
ll int n;
ll int dp[400000][102][2];
ll int ans(ll int ind,ll int tight,ll int sum,ll int d)
{if(ind==n)
{return sum%d==0;}
if(dp[ind][sum][tight]!=-1)
	return dp[ind][sum][tight];
 dp[ind][sum][tight]=0;
if(tight==0)
{for(ll int i=0;i<=9;i++)
{dp[ind][sum][tight]=(dp[ind][sum][tight]%mod+ans(ind+1,0,(sum+i)%d,d)%mod)%mod;

	}


}
else if(tight==1)
{ll int num=s[ind]-'0';
for(ll int i=0;i<=num;i++)
{if(i==num)
dp[ind][sum][tight]=(dp[ind][sum][tight]%mod+ans(ind+1,1,(sum+i)%d,d)%mod)%mod;
else
dp[ind][sum][tight]=(dp[ind][sum][tight]%mod+ans(ind+1,0,(sum+i)%d,d)%mod)%mod;
}
}
return dp[ind][sum][tight];
}
int main()
{
   
 memset(dp,-1,sizeof dp);
ll int d;
cin>>s>>d;
n=s.length();
ll int f=(ans(0,1,0,d));

cout<<((f-1+mod)%mod)<<endl;




}