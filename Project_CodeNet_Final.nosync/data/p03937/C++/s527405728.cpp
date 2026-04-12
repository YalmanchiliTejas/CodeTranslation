#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

int main() {
  int H, W; cin >> H >> W;
  string A[H]; rep(i,H) cin >> A[i];
  int num = 0; rep(i,H) rep(j,W) if (A[i][j]=='#') num++;
  string result = (num==H+W-1) ? "Possible" : "Impossible";
  cout << result << endl;
  return 0;
}