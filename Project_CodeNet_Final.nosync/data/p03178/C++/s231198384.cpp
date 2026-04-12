
//#include "stdc++.h"
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
typedef long long int ll;
inline ll gcd(ll a,ll b){if(a==0) return b;return gcd(b%a,a);}
inline ll power(ll a,ll n,ll m){if(n==0) return 1;ll p=power(a,n/2,m);p=(p*p)%m;if(n%2) return (p*a)%m;else return p; }
#define flush fflush(stdout)
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
#define int long long
int dp[10001][101];
int cal(int n,int md)
{
    return dp[n][md];
}
int32_t main()
{
    IOS;//ifstream fin("input.txt");ofstream fout("output.txt");/*
    string k;
    cin>>k;int d;
    cin>>d;
    dp[0][0]=1;
    for(int i=1;i<=k.length()+1;i++)
    {
        for(int j=0;j<d;j++)
        
        {
            for(int k=0;k<10;k++)
        {
            dp[i][j]=(dp[i][j]%MOD+dp[i-1][(j%d-k%d+d)%d]%MOD)%MOD;
        }
        }
    }
    int s=0,y,x,cnt,ans=0,mx;
    for(int i=0;i<k.length();i++)
    {
        y=k.length()-i-1;
        for(int j=0;j<(k[i]-'0');j++)
        {
            if(y)
            {ans=(ans+cal(y,(d-(s+j)%d)%d)+MOD)%MOD;
               
            }
            else
                if(((s+j)%d)==0)
                    ans=(ans+1)%MOD;
            if(i==0&&j==0)
                ans=ans-1;
        }
        s=s+k[i]-'0';
        s=s%d;
    }
    if((s%d)==0)
        ans=(ans+1)%MOD;
    cout<<ans<<endl;
    return 0;
}

