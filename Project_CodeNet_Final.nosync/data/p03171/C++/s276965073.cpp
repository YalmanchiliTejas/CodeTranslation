/* 
 *     author-->@harshrajani460
 *     codeforces round-567
 *
 */
#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define sz size()
#define mp make_pair
#define p(x) cout<< x << " ";
#define pe(x) cout<< x << endl ;
#define deb(x) cout<<#x<<" : "<<x<<endl;
#define debug(x,y) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<endl;
#define el endl
#define M 998244353 
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROR(i,a,b) for(int i=a;i>=b;i--)
const int N = 1e5 + 5;
int dp[3003][3003][2],a[3003];
int solve(int l,int r,int f)
{
    if(l>r) return 0;
    if(dp[l][r][f]!=-1) return dp[l][r][f];
    int &ans=dp[l][r][f];
    if(f==0)
    return ans=max(a[l]+solve(l+1,r,f^1),a[r]+solve(l,r-1,f^1));
    else
    return ans=min(-a[l]+solve(l+1,r,0),-a[r]+solve(l,r-1,0));
}
int32_t main() 
{ 
    int n;
   cin>>n;
   FOR(i,1,n+1) cin>>a[i];
  memset(dp,-1,sizeof dp);
   cout<<solve(1,n,0);
   
} 