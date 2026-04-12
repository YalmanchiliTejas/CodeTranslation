#include <bits/stdc++.h>
using namespace std;

int main() {
  string N; int k;
  cin >> N >> k;
  int dig = N.size();
  int dp0[dig+1][max(dig+1,4)], dp1[dig+1][max(dig+1,4)];
  for(int i=0;i<=dig;i++){for(int j=0;j<=max(dig,3);j++){dp0[i][j]=0;dp1[i][j]=0;}}
  int n = N[0]-'0';
  for(int d=0;d<=9;d++){
      dp0[1][d>0] += d<n;
      dp1[1][d>0] += d==n;
  }
  for(int i=1;i<dig;i++){
    int n = N[i]-'0';
    for(int j=0;j<=i;j++){
      for(int d=0;d<=9;d++){
        dp0[i+1][j+(d>0)] += dp0[i][j] + (d<n)*dp1[i][j];
        dp1[i+1][j+(d>0)] += (d==n)*dp1[i][j];
      }
    }
  }
  cout << dp0[dig][k]+dp1[dig][k] << endl;
}
