#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <string>
#include <functional>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <bitset>
#define pb push_back
#define YES cout<<"YES"<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define No cout<<"No"<<endl
#define INF (1<<10)
#define LLINF (1LL<<60)
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  int n;
  ll a[200005];
  ll dp[200005][2];

  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=0;i<=n;i++){
    for(int j=0;j<3;j++)dp[i][j]=-LLINF;
  }

  for(int i=1;i<=n;i++){
    if(i==1){
      dp[1][0]=0;
      dp[1][1]=a[i];
    }
    else if(i==2){
      dp[2][0]=0;
      dp[2][1]=max(dp[1][1],a[2]);
    }
    else{
      if(i%2==1){
        dp[i][0]=max(dp[i-1][1],dp[i-2][0]+a[i]);
        dp[i][1]=dp[i-2][1]+a[i];
      }
      else{
        dp[i][0]=max(dp[i-1][0],dp[i-2][0]+a[i]);
        dp[i][1]=max(dp[i-1][1],dp[i-2][1]+a[i]);
      }
    }
  }

  if(n%2==1)cout<<dp[n][0];
  else cout<<dp[n][1];
  
  return 0;
}
