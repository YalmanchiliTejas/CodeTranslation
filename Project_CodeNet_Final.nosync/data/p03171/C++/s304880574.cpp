#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define int long long int
using namespace std;

void desperate_optimization(bool submitting=true,int precision=10)
{
  if(!submitting) return;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(precision);
}
int memo[3005][3005][2];
int arr[3005];
int dpfunction(int i,int j,int player)
{
  if(memo[i][j][player]!=-1) return memo[i][j][player];
  if(i==j) return memo[i][j][player]=((player==1)*2-1)*arr[i];
  if(player)
    return memo[i][j][player]=max(arr[i]+dpfunction(i+1,j,1-player),arr[j]+dpfunction(i,j-1,1-player));
  else
    return memo[i][j][player]=min(-arr[i]+dpfunction(i+1,j,1-player),-arr[j]+dpfunction(i,j-1,1-player));
}
int32_t main()
{
  //freopen("input.txt","r",stdin);
  desperate_optimization(true);
  memset(memo,-1,sizeof(memo));
  int n;
  cin>>n;
  for(int i=0;i<n;i++) cin>>arr[i];
  cout<<dpfunction(0,n-1,1);


  return 0;
}
