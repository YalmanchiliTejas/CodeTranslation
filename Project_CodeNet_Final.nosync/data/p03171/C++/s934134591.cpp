/*   Abhijith  */
#include<bits/stdc++.h>
#include<iomanip>
#include<cmath>
#define lld long long int
#define ld long double
#define mod 1000000007
#define all(v) (v).begin(),(v).end()
#define rep(i,a,b)	for(lld i=a;i<=b;i++)
#define repr(i,a,b) for(lld i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define	endl '\n'
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
vector<lld> v(3001);
lld dp[3001][3001][2];
lld ans=0,n;
lld rec(lld l,lld r,lld pla)
{
    if(dp[l][r][pla]!=-1)
        return dp[l][r][pla];
    if(l>r)
    {
        return dp[l][r][pla]=0;
    }
    if(pla==0)
    {
        ans=max(v[l]+rec(l+1,r,1),v[r]+rec(l,r-1,1));
    }
    else
    {
        ans=min(rec(l+1,r,0)-v[l],rec(l,r-1,0)-v[r]);
    }
    return dp[l][r][pla]=ans;
}
int main()
{
     ios;
     cin>>n;
     rep(i,1,n)
     {
         cin>>v[i];
     }
     rep(l,1,n)
     {
         rep(i,1,n-l+1)
         {
             lld j=i+l-1;
             if(l==1)
             {
                 dp[i][j][0]=v[i];
                 dp[i][j][1]=-v[i];
             }
             else
             {
                 dp[i][j][0]=max(dp[i+1][j][1]+v[i],dp[i][j-1][1]+v[j]);
                 dp[i][j][1]=min(dp[i+1][j][0]-v[i],dp[i][j-1][0]-v[j]);
             }
         }
     }
     //lld ans= rec(1,n,0);
     cout<<dp[1][n][0]<<endl;
    return 0;
}
