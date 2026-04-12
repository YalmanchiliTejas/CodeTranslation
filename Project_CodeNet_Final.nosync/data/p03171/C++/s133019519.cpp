#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
const int N=3005;
ll dp[N][N][2];
ll solve(vector<ll>&a,int c,int start,int end)
{
  if(start>end)
    return 0;

  if(dp[start][end][c])
    return dp[start][end][c];

  ll ans=0;  
  if(c==0)
  {
    ans=a[start]+solve(a,1-c,start+1,end);
    ans=max(ans,a[end]+solve(a,1-c,start,end-1));
  }
  else
  {
    ans=solve(a,1-c,start+1,end)-a[start];
    ans=min(ans,solve(a,1-c,start,end-1)-a[end]);
  }

  return dp[start][end][c]=ans;

}


int main()
{
  ll n;
  cin>>n;
  vector<ll> a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];

  vector<vector<ll>>dp(n,vector<ll>(n,INT_MIN));

  ll ans=solve(a,0,0,n-1);
  cout<<ans<<endl;
}
