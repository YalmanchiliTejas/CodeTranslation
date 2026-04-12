#include<bits/stdc++.h>


using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define all(n) n.begin(),n.end()
#define eb emplace_back
#define endl "\n"

const ll maxn=3e3+50;

const ll maxx=1e13;
const ll mod1=1000000007;
const ll mod=998244353;



ll dp[maxn][maxn][4];
ll a[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("test.txt","r",stdin);
    //freopen("FRAC.INP", "r", stdin);
    // freopen("WALKING.OUT", "w", stdout);
     ll n, s;
     cin>>n>>s;
      for (int i=0;i<=n;i++)
     {
         for (int j=0;j<=s;j++)
         {
            for (int k=0;k<=2;k++)
            {
                dp[i][j][k]=0;
            }

         }
     }
     dp[0][0][0]=1;
     for (int i=1;i<=n;i++) cin>> a[i];
     for (int i=1;i<=n;i++)
     {
         for (int j=0;j<=s;j++)
         {
             dp[i][j][0]=(dp[i][j][0]+dp[i-1][j][0])%mod ;
             dp[i][j][1]=(dp[i][j][1]+dp[i-1][j][0]+dp[i-1][j][1])%mod ;
             dp[i][j][2]=(dp[i][j][2]+dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2])%mod ;
             if (j>=a[i])
             {
                 dp[i][j][1]=(dp[i][j][1]+dp[i-1][j-a[i]][1]+dp[i-1][j-a[i]][0])%mod ;
                  dp[i][j][2]=(dp[i][j][2]+ dp[i-1][j-a[i]][1]+dp[i-1][j-a[i]][0])%mod ;

             }

         }
     }
     cout <<dp[n][s][2];
}
