#include <bits/stdc++.h>

#define int long long
#define counter(m)     for(int i=0;i<m;i++)
#define gcd            __gcd
#define endl           "\n"
#define pb             emplace_back
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x, y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;
int dp[10001][2][101];
int d;
int solve(string &s,int idx,int n,int sum,bool isSmalled,int num)
{
    if(idx==n)
    {
//        if(sum%d==0)
//        cout<<num<<" "<<sum<<endl;
        return sum%d==0;
    }
    if(dp[idx][isSmalled][sum]!=-1)
        return dp[idx][isSmalled][sum];
    int ans=0;
    if(isSmalled)
    {
        for(int i=0;i<10;i++)
        {
            ans+=solve(s,idx+1,n,(sum+i)%d,true,num*10+i);
            ans=ans%mod;
        }
    }
    else{
        int Num=s[idx]-'0';
        for(int i=0;i<Num;i++)
        {
            ans+=solve(s,idx+1,n,(sum+i)%d,true,num*10+i);
            ans%=mod;
        }
        ans+=solve(s,idx+1,n,(sum+Num)%d,false,num*10+Num);
        ans%=mod;
    }
    return dp[idx][isSmalled][sum]=ans;
}
int32_t main() {
    nitin;
    string s;
    cin>>s;
    for(int i=0;i<=10000;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<101;k++)
                dp[i][j][k]=-1;
        }
    }
    int n=s.length();
    cin>>d;
    cout<<(solve(s,0,n,0,false,0)-1+mod)%mod;
    return 0;
}