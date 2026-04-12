#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <iomanip>

using namespace std;

int main(){
   string N;
   int K;
   cin >> N >> K;
   int size = N.size();
   int dp[size+1][K+1][2];
   memset(dp, 0, sizeof(dp));
   int cnt=0;
   dp[0][0][0]=1;
   for(int i=0;i<size;i++){
      int d = N[i]-'0';
      if(d!=0) cnt++;
      for(int j=0;j<=K;j++){
         //cout << i << j << 0 << ":" << dp[i][j][0]<<endl;
         //cout << i << j << 1 << ":" << dp[i][j][1]<<endl;
         if(d==0){
            // case 0
            dp[i+1][j][0]+=dp[i][j][0];
            dp[i+1][j][1]+=dp[i][j][1];
            // case 1-9
            if(j!=K) dp[i+1][j+1][1]+=9*dp[i][j][1];
         }
         else{
            // case 0
            dp[i+1][j][1]+=dp[i][j][1]+dp[i][j][0];
            // case 1-d
            if(j!=K) {
               dp[i+1][j+1][1]+=(d-1)*(dp[i][j][0]+dp[i][j][1]);
               // case d
               dp[i+1][j+1][0]+=dp[i][j][0];
               dp[i+1][j+1][1]+=dp[i][j][1];
               // case d+1-9
               dp[i+1][j+1][1]+=(9-d)*dp[i][j][1];
            }
         }
      }
   }
   int ans=dp[size][K][1];
   if(cnt==K) ans++;
   cout << ans << endl;
   return 0;
}
