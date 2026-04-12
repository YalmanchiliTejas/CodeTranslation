#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <map>
#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int MOD = 1000000007;

int main() {
  int n; cin >> n;
  vector<map<char, int>> S(n, map<char, int>());
  rep(i, n) { 
    string s_tmp; cin >> s_tmp;
    rep(j, s_tmp.length()) S[i][s_tmp[j]]++;
  }

  for (auto x: S[0]) {
    int tmp = x.second;
    rep(i, n) tmp = min(tmp, S[i][x.first]);
    rep(i, tmp) cout << x.first;
  }
  cout << endl;
  return 0;
}