#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const int N = 1e4 + 5;

int n;
vector <int> num;
int d;
string s;
int dp[N][105][2];

ll go(int idx, int sum, bool limit) {
  if(idx == n) return sum == 0;
  if(dp[idx][sum][limit] !=  -1) return dp[idx][sum][limit];
  ll total = 0;
  int R = -1;
  if(limit == 0) R = num[idx];
  else R = 9;
  for(int p = 0; p <= R; p++) {
    bool nlimit = limit;
    if(limit == 0 and p < R) nlimit = 1;
    total = (total + go(idx + 1, (sum + p) % d, nlimit)) % MOD;
  }
  return dp[idx][sum][limit] = total;
}

int main() {
  memset(dp, -1, sizeof dp);
  cin >> s >> d;
  n = s.length();
  for(auto c : s) num.push_back(c - '0');
  //reverse(num.begin(), num.end());
  cout << (go(0, 0, 0) - 1 + MOD) % MOD << '\n';
}