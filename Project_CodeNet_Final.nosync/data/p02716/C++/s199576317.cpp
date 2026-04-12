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
   int N;
   cin >> N;
   int A[N];
   for(int i =0;i<N;i++)cin>>A[i];
   long long dp[N+1][4];
   for(int i = 0 ; i <= N ; i ++){
      for(int j =0; j < 4; j++){
         dp[i][j]=LLONG_MAX/-2;
      }
   } 
   dp[1][0]=A[0];
   dp[1][1]=0;
   for(int i = 1 ; i < N; i++){
      for(int j = 0 ; j <= 1+(N%2) ; j++){
         // つぎに使うかどうか…(i+j)%2==0
         //cout << dp[i][j] <<" ";
         if((i+j)%2==0){
            // あえて使わない
            dp[i+1][j+1]=max(dp[i][j],dp[i+1][j+1]);
            // 普通につかう
            dp[i+1][j]=max(dp[i][j]+A[i],dp[i+1][j]);
         }
         else{
            // 使わない以外の選択肢がない
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
         }
      }
      //cout << endl;
   }
   long long ans = LLONG_MAX/-2;
   for(int i = (N%2); i <= 1+(N%2); i++){
      ans = max(dp[N][i],ans);
   }
   cout << ans << endl;
   return 0;
}
