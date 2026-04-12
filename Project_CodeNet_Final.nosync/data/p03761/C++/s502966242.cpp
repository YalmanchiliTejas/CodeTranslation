#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <regex>
#include <numeric>

using namespace std;


/*--- Macro ---*/
#define rep(i, n) for(int i=0; i<(int)n; i++)
#define rep1(i, n) for(int i=1; i<(int)n; i++)
#define mp make_pair
#define pb push_back


/*---  Type ---*/
typedef long long ll;


/*--- Constants ---*/
template <typename T> const T INF = numeric_limits<T>::max() / 10;
const int MOD = (int)1e9 + 7;


// Floating
const double EPS = 1e-11;
#define EQ0(x) (abs(x) < EPS)
#define EQ(x, y) (abs(a-b) < EPS)

// -------------------------------------------------------------------------------------

int main() {
  int n;
  vector<string> s;

  cin >> n;
  s.resize(n);
  rep(i, n) cin >> s[i];

  vector< vector<int> > counts(26, vector<int>(n, 0)); // 1行目はa, 2行目はb, ...
  rep(i, n) {
    rep(j, s[i].length()) {
      counts[s[i][j]-'a'][i]++;
    }
  }

  string ans = "";
  rep(i, 26) {
    auto min_e = min_element(counts[i].begin(), counts[i].end());
    rep(j, *min_e) ans += (i + 'a');
  }
  cout << ans << endl;
  return 0;
}