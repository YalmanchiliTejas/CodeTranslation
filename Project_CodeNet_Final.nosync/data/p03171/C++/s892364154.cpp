#include<bits/stdc++.h>

#define int            long long int
#define float          long double
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define inf            1e18
#define set_pre(x,y)   fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
using namespace std;
int power(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
int modi(int a, int m)
{
    return power(a, m - 2, m);
}
int dp[3001][3001];
int solve(int i,int j,vector<int>&v)
{
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(j-i==1)
        return max(v[i],v[j]);
    else return dp[i][j]=max(min(solve(i+1,j-1,v),solve(i+2,j,v))+v[i],min(solve(i+1,j-1,v),solve(i,j-2,v))+v[j]);
}
int32_t main(){
    int n;
    cin>>n;
    vector<int>v(n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j]=-1;
        }
    }
    int x=solve(0,n-1,v);
    cout<<2*x-sum<<endl;
}