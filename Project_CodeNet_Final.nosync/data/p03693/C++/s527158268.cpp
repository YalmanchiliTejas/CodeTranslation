#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)

ll mod = 1e09;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int r, g, b;
  cin >> r >> g >> b;
  if((100 * r + 10 * g + b) % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
