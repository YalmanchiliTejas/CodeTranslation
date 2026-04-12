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
int dp[10001][101][2];
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
int sumdigi(int num)
{
    int sum=0;
    while(num)
    {
        sum+=num%10;
        num/=10;
    }
    return sum;
}
int32_t main() {
    nitin;
    string s;
    cin>>s;
    int n=s.length();
    cin>>d;
//    for(int i=0;i<s[0]-'0';i++)
//        dp[1][i][0]=1;
//    dp[1][s[0]-'0'][1]=1;
dp[0][0][1]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<d;j++)
        {
            int num=s[i]-'0';
            for(int k=0;k<10;k++)
            {
                dp[i+1][(j+k)%d][0]=(dp[i+1][(j+k)%d][0]+dp[i][j][0])%mod;
            }
            for(int k=0;k<num;k++)
            {
                dp[i+1][(j+k)%d][0]=(dp[i+1][(j+k)%d][0]+dp[i][j][1])%mod;
            }
            dp[i+1][(j+num)%d][1]=(dp[i+1][(j+num)%d][1]+dp[i][j][1])%mod;
        }
    }
//    for(int i=0;i<=n;i++)
//    {
//        for(int j=0;j<d;j++)
//        {
//            cout<<dp[i][j][0]<<" "<<dp[i][j][1]<<"   "<<i<<" "<<j<<endl;
//        }
//    }
    cout<<(dp[n][0][0]+dp[n][0][1]-1+mod)%mod<<endl;

    return 0;
}