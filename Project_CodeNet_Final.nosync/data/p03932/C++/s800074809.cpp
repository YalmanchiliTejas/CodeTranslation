#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <complex>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << (x) << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 310

int h,w;
int a[SIZE][SIZE];
ll dp[SIZE][SIZE][SIZE];

int main(){
  
  scanf("%d%d",&h,&w);
  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      scanf("%d",a[i]+j);
      for(int k=0;k<w;k++) dp[i][j][k] = -LLINF;
    }
  }

  dp[0][0][0] = a[0][0];
  
  for(int i=0;i<h;i++){
    if(i > 0)
      for(int j=0;j<w;j++){
        for(int k=0;k<w;k++){
          if(j==k) dp[i][j][k] = dp[i-1][j][k] + a[i][j];
          else dp[i][j][k] = dp[i-1][j][k] + a[i][j] + a[i][k];
        }
      }
    
    for(int j=0;j<w-1;j++){
      for(int k=0;k<w;k++){
        if(j+1 != k)
          dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k] + a[i][j+1]);
        else
          dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k]);          
      }
    }
    for(int j=0;j<w;j++){
      for(int k=0;k<w-1;k++){
        if(j < k+1)
          dp[i][j][k+1] = max(dp[i][j][k+1], dp[i][j][k] + a[i][k+1]);
        else
          dp[i][j][k+1] = max(dp[i][j][k+1], dp[i][j][k]);
      }
    }
  }

  printf("%lld\n",dp[h-1][w-1][w-1]);
  
  return 0;
}

