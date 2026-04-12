#include <iostream>
using namespace std;
 
#define MAXN 3010
 
int N;
long long dp[MAXN][MAXN];
long long a[MAXN];
long long pre[MAXN];
 
int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> a[i];
  for (int i = 1; i <= N; i++) pre[i] = pre[i-1] + a[i];
  
  for (int i = 1; i <= N; i++) dp[i][i] = a[i];
  
  for (int j = 1; j < N; j++) {
    for (int i = 1; i+j <= N; i++) {
      dp[i][i+j] = max(a[i]+(pre[i+j]-pre[i])-dp[i+1][i+j],a[i+j]+(pre[i+j-1]-pre[i-1])-dp[i][i+j-1]);
    }
  }
      
      
  long long x = dp[1][N];
  long long y = pre[N] - x;
  cout << x-y << endl;
}