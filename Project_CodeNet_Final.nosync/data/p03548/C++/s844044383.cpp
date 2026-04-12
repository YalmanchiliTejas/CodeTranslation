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

  ll x, y, z;
  cin >> x >> y >> z;

  ll c = 0, sp = z;

  while(1){
    sp += y + z;
    if(sp > x){
      cout << c << endl;
      return 0;
    }
    c++;
  }


  return 0;
}
