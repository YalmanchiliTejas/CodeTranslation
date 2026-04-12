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

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 51


int main(){
  int n,m;
  bool way[10][10] = {};
  int a,b;
  int dp[1<<8][10] = {};
  
  
  scanf("%d%d",&n,&m);

  for(int i=0;i<m;i++){
    scanf("%d%d",&a,&b);
    a--; b--;

    way[a][b] = way[b][a] = true;
  }

  dp[1][0] = 1;

  for(int i=0;i<(1<<n)-1;i++){

    for(int j=0;j<n;j++){
      if(!(i & (1 << j))) continue;
      
      for(int k=0;k<n;k++){
        if(i & (1 << k)) continue;
        if(!way[j][k]) continue;
        
        dp[i | (1<<k)][k] += dp[i][j];
      } 
    }
  }

  ll ans_sum = 0;

  for(int i=0;i<n;i++){
    ans_sum += dp[(1<<n)-1][i];
  }
  
  printf("%lld\n",ans_sum);
  
  return 0;
}
