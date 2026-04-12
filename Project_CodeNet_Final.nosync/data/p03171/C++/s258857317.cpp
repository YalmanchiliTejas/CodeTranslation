#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define vi vector<ll>
#define all(a) (a).begin(), (a).end()
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define tr(it, a)   for(auto it=a.begin();it!=a.end();it++)
#define pb push_back
#define endl  "\n"
const ll MAX=4e3+3;
const ll mod=1e2+7;
vi a(MAX);
ll dp[MAX][MAX];
ll fun(ll i,ll j)
{
    if(i>j)
        return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
            ll x,y;
    x=a[i]+min(fun(i+2,j),fun(i+1,j-1));
    y=a[j]+min(fun(i+1,j-1),fun(i,j-2));
    dp[i][j]=max(x,y);
    return dp[i][j];

}
int main()
{
   FASTIO
   int t=1;
   //cin>>t;
   while(t--)
  {
        ll n,c;cin>>n;
        ll sum=0;
        rep(i,0,n)
        {
            cin>>a[i];
            sum+=a[i];
        }
        memset(dp,-1,sizeof(dp));
        ll ans=fun(0,n-1);
        ans=2*ans-sum;
        cout<<ans;
   }
 return 0;
}
