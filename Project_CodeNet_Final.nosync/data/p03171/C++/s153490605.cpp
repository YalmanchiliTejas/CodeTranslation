#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
using namespace std;
vector<long long>a;
vector<vector<long long>>dp;
long long sa(long long b,long long e)
{
  if(dp[b][e]!=-1)return dp[b][e];
  if(b==e)return a[b];
  if(e-b==1)
  {
    return abs(a[e]-a[b]);
  }
  long long tmp1,tmp2;
  tmp1=min(a[b]-a[b+1]+sa(b+2,e),a[b]-a[e]+sa(b+1,e-1));
  tmp2=min(a[e]-a[b]+sa(b+1,e-1),a[e]-a[e-1]+sa(b,e-2));
  dp[b][e]=max(tmp1,tmp2);
  return dp[b][e];
}
int main()
{
  ios::sync_with_stdio(false);
  long long n;
  cin>>n;
  a=vector<long long>(n);
  dp=vector<vector<long long>>(n,vector<long long>(n,-1));
  for(long long i=0;i<n;i++)
  {
    cin>>a[i];
  }
  cout<<sa(0,n-1)<<endl;
  return 0;

}
