/* 
    Author : Jeff Ahn
    Sat 13 Jun 2020 01:57:28 AM PDT 
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define endl '\n'
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const map<T,T> &vec){ os<< "{"; for (auto p : vec) os << "(" << p.first << "," << p.second << "), "; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_map<T,T>&vec){ os<< "{"; for (auto p : vec) os << "(" << p.first << "," << p.second << "), "; os << "}"; return os; }

string n;
int k;

int dp[110][2][5];

int solve(int i, int flag, int n0) {
  if (n0 > k) return 0;
  if (i == n.size()) {
    return (n0 == k);
  }
  int& res = dp[i][flag][n0];
  if (res != -1) return res;
  res = 0;
  int maxi = flag ? n[i] - '0' : 9;
  for (int idx = 0; idx <= maxi; idx++) {
    res += solve(i + 1, flag && (idx == maxi), n0 + (idx != 0));
  }
  return res;
}

signed main() {
  fastio;
  cin >> n >> k;
  memset(dp, -1, sizeof(dp));
  cout << solve(0, 1, 0) << endl;
  
}
