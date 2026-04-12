#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll dp[3005][3005];
bool solved[3005][3005];
int l[3005];
int n;

ll solve(int lhs, int rhs) {
  if(lhs == rhs) {
    return l[lhs];
  }
  if(solved[lhs][rhs]) return dp[lhs][rhs];
  solved[lhs][rhs] = true;
  dp[lhs][rhs] = max(l[lhs] - solve(lhs+1, rhs), l[rhs] - solve(lhs, rhs-1));
  return dp[lhs][rhs];
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
  }
  cout << solve(0, n-1) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}
