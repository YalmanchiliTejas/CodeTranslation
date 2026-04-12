#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define all(a) (a).begin(),(a).end()
#define X first
#define Y second
#define inf 2e9+5
using namespace std;
void solve()
{
  int n; cin>>n; int a[n];
  for(int i=0;i<n;i++)cin>>a[i];
  int trn=1; int dp[n][n];
  for(int i=0;i<n;i++)
  {
      trn=1-trn;
    for(int j=0;j+i<n;j++)
  {
      if(!i){dp[j][j]=a[j]; continue;}
      if(!trn)
          dp[j][j+i]=max(dp[j+1][j+i]+a[j],dp[j][j+i-1]+a[j+i]);
      else
        dp[j][j+i]=min(dp[j+1][j+i]-a[j],dp[j][j+i-1]-a[j+i]);
  }
  }
  if(!trn)cout<<dp[0][n-1];
  else cout<<-dp[0][n-1];
  return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; t=1;
    while(t--)solve();
    return 0;
}
