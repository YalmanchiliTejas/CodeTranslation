#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n) for (int i=1; i < (int)(n); i++)
#define rrep(i, n) for (int i=((int)(n)-1); i>=0; i--)
#define rreps(i, n) for (int i=((int)(n)-1); i>0; i--)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using lint = long long;
using p = pair<int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  int x;
  scanf("%d", &x);
  string s = x >= 30 ? "Yes" : "No";
  cout << s << endl;
  return 0;
}
