#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  int a[n];
  long long pts[n][n][2];
  for(int i=0;i<n;i++) 
    cin >> a[i];
  for(int l=0;l<n;l++) {
    for(int i=0;i<n;i++) {
      if (i+l>=n) {
        continue;
      }
      if (l==0) {
        pts[i][i+l][0] = a[i];
        pts[i][i+l][1] = 0;
      } else {
        // if I remove from right
        auto fromRight = a[i+l] + pts[i][i+l-1][1];
        auto fromLeft = a[i] + pts[i+1][i+l][1];
        if (fromRight - pts[i][i+l-1][0] > fromLeft - pts[i+1][i+l][0]) {
          pts[i][i+l][0] = fromRight;
          pts[i][i+l][1] = pts[i][i+l-1][0];
        } else {
          pts[i][i+l][0] = fromLeft;
          pts[i][i+l][1] = pts[i+1][i+l][0];
        }
      }
    }
  }
  cout << pts[0][n-1][0] - pts[0][n-1][1] << '\n';
  return 0;
}