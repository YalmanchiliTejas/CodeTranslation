#include <iostream>

using namespace std;
typedef long long ll;

string n;
int k;
ll dp1[110][4]; // < n
ll dp2[110][4]; // maybe < n

void solve() {
  dp2[0][0] = 1;
  for (int i=0;i<n.size();i++) {
    for (int j=0;j<=k;j++) {
      dp1[i+1][j] += dp1[i][j];
      if (n[i] == '0') {
        dp2[i+1][j] += dp2[i][j];
      } else {
        dp1[i+1][j] += dp2[i][j];
      }
      if (j + 1 > k) {
        continue;
      }
      for (int l=1;l<=9;l++) {
        if (n[i] - '0' == l) {
          dp2[i+1][j+1] += dp2[i][j];
        }
        dp1[i+1][j+1] += dp1[i][j];
        if (n[i] - '0' > l) {
          dp1[i+1][j+1] += dp2[i][j];
        }
      }
    }
  }
  cout << dp1[n.size()][k] + dp2[n.size()][k] << endl;
}

int main() {
  cin >> n >> k;
  solve();
}
