#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long int dp[10004][101][2];
string k;
long long int d,len;
long long int solve(long long int index,long long int rem,long long int check=1)
{
    if(index==len)return (rem==0);
    if(dp[index][rem][check]!=-1)return dp[index][rem][check];
    long long int bound=9,ans=0;
    if(check==1)bound=(k[index]-48);
    for(int i=0;i<=bound;i++)ans=(ans+solve(index+1,(rem+i)%d,check && (i==k[index]-48)))%mod;
    return dp[index][rem][check]=ans;
}
int main()
{
    long long int i,j,x,y,z;
    cin>>k;
    cin>>d;
    len=k.size();
    for(i=0;i<=10002;i++)for(j=0;j<=100;j++)for(int l=0;l<2;l++)dp[i][j][l]=-1;
    cout<<(solve(0,0)-1+mod)%mod;
}