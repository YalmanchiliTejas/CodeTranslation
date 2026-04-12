#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100005;
const int MOD = 1000000007;

vector<int> num;
int k; ll dp[N][105][2];

ll fun(int p, int s, int f) {
  if (p == num.size()) return s % k == 0;
  ll &ret = dp[p][s][f];
  if (ret != -1) return ret;
  ret = 0;
  int j = f ? 9 : num[p];
  for (int i = 0; i <= j; i++) {
    ret += fun(p + 1, (s + i) % k, i < j ? 1 : f);
    ret %= MOD;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s >> k;
  for (auto i : s) {
    num.push_back(i - '0');
  }
  memset(dp, -1, sizeof dp);
  cout << (fun(0, 0, 0) - 1 + MOD) % MOD << endl;
  return 0;
}
