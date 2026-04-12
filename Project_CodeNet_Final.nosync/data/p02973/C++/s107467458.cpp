#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define INF 2100000000
#define LLINF 10000000000000000ll
#define MOD 1000000007

bool dbgflag = false; //debug

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> color(2*n-1);
  color[n-1] = -INF;
  for (int i = 1; i < n; i++) {
    color[n+i-1] = INF;
    color[n-i-1] = -1 * INF;
  }
  
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (dbgflag) cout <<"a " << a << endl;
    *(lower_bound(color.begin(), color.end(), a) - 1) = a;
  }

  if (dbgflag) {
    for (int i = 0; i < color.size(); i++) {
      cout << color[i] << endl;
    }
  }

  cout << (int)(lower_bound(color.begin(), color.end(), INF) - upper_bound(color.begin(), color.end(), -1*INF)) << endl;
}
