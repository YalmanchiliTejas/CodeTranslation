#include <iostream>
#include <vector>
#include <bitset>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;
 
int main(){
  int N;
  cin >> N;

  vector<int> a(N);
  vector<vector<ll>> dp(N+1,vector<ll>(N+1));

  for (int i = 0; i < N; i++){
    cin>> a[i];
  }
  bool taro=(N%2==1);
  for(int i=1;i<=N;i++){
    for (int j = 0; j <=N-i; j++){
      if(taro){
        dp[j][j+i]=max( a[j]+dp[j+1][j+i], a[j+i-1]+dp[j][j+i-1]);
      }else{
        dp[j][j+i]=min(-a[j]+dp[j+1][j+i],-a[j+i-1]+dp[j][j+i-1]);
      }
      //cout << j <<" "<< j+i << " " << dp[j][j+i] <<endl;
    }
    taro^=true;
  }

  cout<< dp[0][N] << endl;

  return 0;
}
