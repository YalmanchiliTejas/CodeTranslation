#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define irep(i, a, n) for (int i = a; i < (int)(n); ++i)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define rrep1(i, n) for (int i = (int)(n); i >= 1; --i)
#define allrep(V, v) for (auto&& V : v)
#define all(x) (x).begin(), (x).end()
using lint = long long;
const int INF = 1 << 29;
const double EPS = 1e-9;
using namespace std;

int main(void) {
  char c;
  cin >> c;
  cout << (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' ? "vowel" : "consonant") << endl;
  return 0;
}