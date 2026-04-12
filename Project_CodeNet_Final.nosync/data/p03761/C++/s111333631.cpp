#include <bits/stdc++.h>
#define REP(i, n) for (long long i = 0; i < (long long)n; i++)
//#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Vl = vector<ll>;
using vi = vector<int>;
using Graph = vector<vi>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(15); //"for float-base
  // problem"
  int n;
  cin >> n;
  vector<string> S(n);
  REP(i, n) cin >> S.at(i);
  string ans = "";
  sort(S.at(0).begin(), S.at(0).end());
  for (auto s : S.at(0)) {
    bool FLG = true;
    for (int j = 1; j < n; j++) {
      bool flag = false;
      for (int k = 0; k < S.at(j).size(); k++) {
        if (s == S.at(j).at(k)) {
          S.at(j).at(k) = '0';
          flag = true;
          break;
        }
      }
      if (!flag) {
        FLG = false;
        break;
      }
    }
    if (FLG) ans += s;
  }
  cout << ans << endl;
}