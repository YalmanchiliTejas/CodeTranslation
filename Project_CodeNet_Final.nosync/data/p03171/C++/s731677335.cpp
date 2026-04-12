#include <iostream>
using namespace std;

#define N 3000
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
#define MIN(X,Y) ((X)<(Y)?(X):(Y))

long long dp[N][N]; // dp[l][r] = [l,r]のX-Yの最適値

int main(void){
  int n, a[N];
  
  cin >> n;
  for (int i=0; i<n; i++){
    cin >> a[i];
    dp[i][i] = n%2? a[i]: -a[i];
  }
    
  for (int ln=2; ln<=n; ln++){
    for (int i=0; i<=n-ln; i++){
      if (ln%2 == n%2){ // taro (pl.1)
        dp[i][i+ln-1] = MAX(dp[i+1][i+ln-1]+a[i], dp[i][i+ln-2]+a[i+ln-1]);
      } else { // jiro (pl.2)
        dp[i][i+ln-1] = MIN(dp[i+1][i+ln-1]-a[i], dp[i][i+ln-2]-a[i+ln-1]);
      }
//    cout << "[" << i << "," << i+ln-1 << "]";
//    cout << " -> " << dp[i][i+ln-1];
//    cout << " (" << (ln%2==n%2?"T)":"J)") << endl;
    }
  }
  cout << dp[0][n-1] << endl;
  return 0;
}
