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
  ll x,y,z; cin >> x >> y >> z;
  ll k = 1;
  while(true){
    if(k*y+(k+1)*z<=x && x < (k+1)*y+(k+2)*z){
      cout << k << endl;
      return 0;
    }
    k++;
  }
}