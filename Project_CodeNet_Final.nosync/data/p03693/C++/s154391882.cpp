#include <bits/stdc++.h>
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define IFOR(i, m, n) for(int i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const ll INF = 1e18;
/* テンプレートここまで */

int main() {
  ll r,g,b; cin >> r >> g >> b;
  if((10*g+b)%4==0) cout << "YES" << endl;
  else cout << "NO" << endl;
}
