#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end() 
#define MOD 1000000007
#define N 200005
#define pll pair<ll,ll>
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);srand(time(NULL));
ll dp1[N][3],dp2[N][2],a[N],n;
ll solve1(ll id,ll taken)
{
     if(id==n+1 && taken==0)
     {
          return -1e18;
     }
     if(id==n+2 && taken==1)
     {
          return -1e18;
     }
     if(id>=n)    return 0;
     ll ans = dp1[id][taken];
     if(ans!=-1)    return ans;
     ans = -1e18;
     if(taken<=1)
     {
          ans = max(ans,a[id]+solve1(id+3,taken+1));
     }
     ans = max(ans,a[id]+solve1(id+2,taken));
     return dp1[id][taken] = ans;
}
ll solve2(ll id,ll taken)
{
     if(id>=n)   return 0;
     ll ans = dp2[id][taken];
     if(ans!=-1)    return ans;
     ans = -1e18;
     if(taken==0)
     {
          ans = max(ans,a[id]+solve2(id+3,1));
     }
     ans = max(ans,a[id]+solve2(id+2,taken));
     return dp2[id][taken] = ans;
}
void solve()
{ 
     cin >> n;
     for(ll i=0;i<n;i++)   cin >> a[i];
     if(n%2)
     {
          memset(dp1,-1,sizeof(dp1));
          memset(dp2,-1,sizeof(dp2));
          ll ans = solve2(1,0);
          ll sum = 0;
          for(ll i=2;i<n;i+=2)    sum += a[i];
          ans = max(ans,sum);
          sum = 0;
          ll ele = 0;
          for(ll i=0;i<n;i+=2)
          {
               ele++;
               sum += a[i];
               if(ele==n/2)     break;
          }
          ans = max(ans,sum);
          ll ans1 = solve1(0,0);
          ans = max(ans,ans1);
          cout<<ans;
     }
     else
     {
          memset(dp2,-1,sizeof(dp2));
          ll ans = solve2(0,0);
          ll sum = 0;
          for(ll i=1;i<n;i+=2)     sum += a[i];
          ans = max(ans,sum);
          cout<<ans;
     }
}
int main()
{
     FAST;
     ll t = 1;
  ///   cin >> t;
     while(t--)
     {     
          solve();
     }
}