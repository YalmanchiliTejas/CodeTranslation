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
#include <limits>
#include <iomanip>

using namespace std;

int main(){
  string K;
  int D;
  cin >> K >> D;
  int size= K.size();
  long long dp[size+1][D][2];
  for(int i=0; i<=size; i++){
     for(int j=0; j< D; j++){
        for(int k=0; k<2; k++){
           dp[i][j][k] = 0;
        }
     }
  }
  dp[0][0][0] = 1;
  int mod = 1000000007;
  for(int i = 0 ; i < size; i++){
     for(int j=0; j < D; j++){
        for(int k = 0 ; k <= 9; k++){
           int prevD = (j+D*k-k)%D;
           int d = K[size-1-i]-'0';
           if( k > d ){
              dp[i+1][j][1] += dp[i][prevD][0];
              dp[i+1][j][1] += dp[i][prevD][1];
              dp[i+1][j][1] %= mod;
           }
           else if( k < d ){
              dp[i+1][j][0] += dp[i][prevD][0];
              dp[i+1][j][0] += dp[i][prevD][1];
              dp[i+1][j][0] %= mod;
           }
           else{
              dp[i+1][j][0] += dp[i][prevD][0];
              dp[i+1][j][0] %= mod;
              dp[i+1][j][1] += dp[i][prevD][1];
              dp[i+1][j][1] %= mod;
           }
        }
        //cout << i+1 <<", "<< j <<" " ;
        //for(int k = 0 ; k < 2; k++){
        //   cout << dp[i+1][j][k] <<", ";
        //}
        //cout << endl;
     }
  }
  cout << (dp[size][0][0]+mod-1)%mod<<endl;

  return 0;
}
