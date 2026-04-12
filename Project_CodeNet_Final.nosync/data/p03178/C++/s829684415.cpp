#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;
const int MOD = 1000000007;


string s;
int d;

int dp[105][2];
int ndp[105][2];

void solve() {
  cin >> s >> d;
  dp[0][1] = 1;
  for(int i = 0; i < s.size(); i++) {
    memset(ndp, 0, sizeof(ndp));
    for(int a = 0; a < d; a++) {
      for(int b = 0; b < 2; b++) {
        int bound = b == 1 ? s[i] - '0' : 9;
        for(int x = 0; x <= bound; x++) {
          ndp[(a+x)%d][b && x == bound] += dp[a][b];
          if(ndp[(a+x)%d][b && x == bound] >= MOD) ndp[(a+x)%d][b && x == bound] -= MOD;
        }
      }
    }
    memcpy(dp, ndp, sizeof(dp));
  }
  cout << (dp[0][0] + dp[0][1]+MOD-1)%MOD << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}
