#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mkp make_pair
#define rep(i,s,f) for(i=s;i<f;i++)
#define db cout<<'h'<<'i'<<endl 
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define vi vector<int>
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define PI 3.14159265
#define mod 1000000007
#define mod2 998244353
#define space 10005
#define lg 18
//<<fixed << setprecision(9)
ll dp[space][101][2];//to be or not to be
int main()
{
    int n,i,j,t;
    boost;

    string s;
    int d;
    cin>>s>>d;
    n=s.size();
    int x[n];
    rep(i,0,n)x[i]=s[i]-'0';
    rep(i,0,x[0])    
    {
        dp[0][i%d][0]+=1;
    }
    dp[0][x[0]%d][1]=1;
    int k;
    rep(i,1,n)
    {
        rep(j,0,d)
        {
            rep(k,0,10)
            {
                dp[i][(j+k)%d][0]+=dp[i-1][j][0];
                if(k<x[i]) dp[i][(j+k)%d][0]+=dp[i-1][j][1];
                else if(k==x[i])
                {
                      dp[i][(j+k)%d][1]+=dp[i-1][j][1];
                      dp[i][(j+k)%d][1]%=mod;
                }
                dp[i][(j+k)%d][0]%=mod;

            }
        }
    }

    cout<<(dp[n-1][0][0]+dp[n-1][0][1]-1+mod)%mod;

    return 0;
}

