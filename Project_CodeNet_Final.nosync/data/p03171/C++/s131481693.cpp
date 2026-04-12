
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define eb          emplace_back
#define c(P)        cout<<P<<"\n"
#define pii         pair<ll,ll>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define F           first
#define S           second
#define mp(x,y)     make_pair(x,y) 
#define mem(a,val)  memset(a,val,sizeof(a))
#define fr(i,a,n)   for(ll i=a;i<n;i++)
#define frr(i,a,n)  for(ll i=n-1;i>=a;i--)


const ll N   =  3005;
const ll mod = 1e9 + 7;

using namespace std;

ll dp[N][N]; // for   taro
void solve()
{
   ll n;
   cin>>n;
   ll a[n];
   for (int i = 0; i < n; ++i)
   {
     /* code */
    cin>>a[i];
   }
   // dp[n-1][0] - ans when all are over
  for (int i = 0; i <n ; ++i)
  {
    for(ll j = i;j>=0;j--)
    {
      if(i==j)
      dp[i][j] = a[i];
      else dp[i][j] = max(a[i] - dp[i-1][j],a[j] - dp[i][j+1]);

    }
  }
  cout<<dp[n-1][0]<<"\n";
}

signed main(){
  
      ios_base::sync_with_stdio(false);   
      cin.tie(NULL);
      ll T=1;
      //cin>>T;
      while(T--)
      {
      solve();
      }
      return 0;
    }
