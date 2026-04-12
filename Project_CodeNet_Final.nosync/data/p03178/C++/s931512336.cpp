#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
vector < vector < int > > dp(105, vector < int > (2, 0));
int d;
string s;
int add(int a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
  return a;
}
int sub(int a, int b) {
  a -= b;
  if (a < 0) {
    a += MOD;
  }
  return a;
}
int main() {
  ios_base::sync_with_stdio(false);
  int ans = 0;
  cin >> s >> d;
  // DP[sum][f] --> numarul de moduri in care putem obtine DP[nr % d] (f == 0 daca suntem pe margine, f == 1 daca nu)
  dp[0][0] = 1;
  for (int pos = 0; pos < s.size(); pos++) {
    vector < vector < int > > new_dp(105, vector < int > (2, 0));
    for (int sum = 0; sum <= d - 1; sum++) {
        for (bool f : {0, 1}) {
          for (int cur_digit = 0; cur_digit <= 9; cur_digit++) {
            if (cur_digit > s[pos] - '0' && !f) {
              break;
            }
            new_dp[(sum + cur_digit) % d][f || (cur_digit < s[pos] - '0')] = add(new_dp[(sum + cur_digit) % d][f || (cur_digit < s[pos] - '0')], dp[sum][f]);
          }
        }
     }
     dp = new_dp;
  }
  cout << sub(add(dp[0][0], dp[0][1]) , 1) << "\n";
  return 0;
}
