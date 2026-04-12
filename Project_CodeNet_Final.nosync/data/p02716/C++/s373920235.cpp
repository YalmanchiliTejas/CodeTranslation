#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  long long a[n+1];
  for (int i=0; i<n; i++) cin>>a[i+1];
  long long dp[n+1][3];
  for (int i=0; i<n+1; i++) {
    dp[i][0] = -1e16;
    dp[i][1] = -1e16;
    dp[i][2] = -1e16;
  }
  dp[1][2] = a[1];
  dp[2][1] = a[2];
  if (n > 2) {
    dp[3][1] = a[3];
  }
  if (n > 4) {
    dp[4][0] = a[4];
  }
  for (int i=3; i<n+1; i++) {
    for (int j=2;;j++) {
      if ((i - j) / 2 + 1 < i / 2 - 1) {
        break;
      }
      if (i - j < 0) {
        break;
      }
      for (int k=0; k<3; k++) {
        if (dp[i-j][k] == -1e16) {
          continue;
        }
        int cnt = (i - j) / 2 + k;
        if (cnt == i / 2 - 1) {
          dp[i][0] = max(dp[i-j][k] + a[i], dp[i][0]);
        } else if (cnt == i / 2) {
          dp[i][1] = max(dp[i-j][k] + a[i], dp[i][1]);
        } else if (cnt == i / 2 + 1) {
          dp[i][2] = max(dp[i-j][k] + a[i], dp[i][2]);
        }
      }
    }
  }
  // for (int i=0; i<3; i++) {
  //   for (int j=0; j<n; j++) {
  //     if (dp[j+1][i] == -1e16) {
  //       printf("-INF ");
  //     } else {
  //       printf("%4d ", dp[j+1][i]);
  //     }
  //   }
  //   cout<<endl;
  // }
  if (n % 2 == 0) {
    cout<<max(dp[n][1], dp[n-1][2])<<endl;
  } else {
    cout<<max(dp[n][1], max(dp[n-1][1], dp[n-2][2]))<<endl;
  }
}