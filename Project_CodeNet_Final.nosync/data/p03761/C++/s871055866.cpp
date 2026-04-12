#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, e) for (int i = s; i < e; ++i)
#define sort_(a) stable_sort(a.begin(), a.end())
#define rsort(a) stable_sort(a.rbegin(), a.rend())
#define sum(a) accumulate(a.begin(), a.end(), 0LL)
#define join(a, d) accumulate(a.begin() + 1, a.end(), a[0], [](string s, string t) {return s + d + t;})
#define all(a) a.begin(), a.end()
// #define __lcm(a, b) std::__detail::__lcm(a, b)
typedef long long ll;
const long mod = 1e9 + 7;

string lcs(string s1, string s2) {
  vector<int> dp;
  string ret;
  for (auto s : s2) {
    int bgn_i = 0;
    int chr_i = 1;
    rep(i, 0, int(dp.size())) {
      chr_i = s1.find(s, bgn_i) + 1;
      if (not chr_i) break;
      dp[i] = min(dp[i], chr_i);
      bgn_i = dp[i];
    }
    if (chr_i) {
      chr_i = s1.find(s, bgn_i) + 1;
      if (chr_i) {
        dp.push_back(chr_i);
        ret += s1[chr_i-1];
      }
    }
  }
  return ret;
}


int main(void) {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  vector<string> S(N);
  rep(i, 0, N) {
    cin >> S[i];
    sort_(S[i]);
  }

  string ans;
  ans = accumulate(S.begin(), S.end(), S[0], lcs);
  cout << ans << endl;
  return 0;
}
