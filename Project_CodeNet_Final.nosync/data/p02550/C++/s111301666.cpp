#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define int long long int
#define vec vector<int>
#define mp map<int,int>
#define inf 1e18
using namespace std;
vector<int> v;
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tt=1;
  //cin>>tt;
  while(tt--)
  {
    int n,x,mod,i;
    cin>>n>>x>>mod;
    int dp[100011]={0},h[100011]={0};
    dp[1]=x,h[x]=1;
    for(i=2;1;i++)
    {
      dp[i]=((dp[i-1]) * (dp[i-1]))%mod;
      if(h[dp[i]])
        break;
      h[dp[i]]=i;
    }
    int y=i-1,z=h[dp[i]];
    for(i=2;i<=z-1;i++)
       dp[i]+=dp[i-1];
    int r=dp[z-1];
    dp[z-1]=0;
    for(i=z+1;i<=y;i++)
       dp[i]+=dp[i-1];
    int ans=(((((n-z+1)/(y-z+1))) * (dp[y]))+dp[(n-z+1)%(y-z+1)+z-1]+r);
    cout<<ans<<"\n";
  }
}
