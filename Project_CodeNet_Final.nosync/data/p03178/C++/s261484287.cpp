#include <bits/stdc++.h>
#include <stdio.h>
typedef long long int LL;
#define fr(i,p,n) for(LL i=p;i<n;i++)
#define fr1(i,p,n) for(LL i=p;i>=n;i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define precise cout << std::setprecision(10) << std::fixed;

using namespace std;
 
int D;
vector<int> N;
#define MOD 1000000007


void input() {
  string n;
  cin >> n >> D;

  for (auto x: n) {
    N.push_back(x - '0');
  }
}
int dp[10002][2][101];


int solveRec(vector<int> &digits, int k = 0, bool tight = true, int sum = 0) {
  // 整数文字列の最後まで到達
  if (k == digits.size()) {
    return sum % D == 0;
  }
  int x = digits.at(k);
  int r = tight ? x : 9; // その桁において最大の場合は次の桁で制限がかかる

  int res = dp[k][tight][sum];
  if (~res) return res; // DP
  res = 0;
  for (int i=0; i<=r; i++) {
    res += solveRec(digits, k + 1, tight && i == r, (sum + i) % D);
    res %= MOD;
  }
  dp[k][tight][sum] = res;
  return res;
}


void solve() {
  memset(dp, -1, sizeof(dp));
  int total = solveRec(N);
  total = (total - 1) % MOD; // remove 0
  if (total < 0) total += MOD;
  cout << total << endl;
}


int main() {
  input();
  solve();
  return 0;
}