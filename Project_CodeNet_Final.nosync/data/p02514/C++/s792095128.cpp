#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;

ll n[3];
int main(){
  ll a, b, c, d, e, f;
  while(cin >> a >> b >> c >> d >> e >> f&&(a || b|| c|| d || e || f)){
    n[0] = a + d;
    n[1] = b + e;
    n[2] = c + f;
    ll l = min(n[0], min(n[1], n[2]));
    ll res = 0;
    rep(i, min(l + 1, 100LL)){
      ll c = i;
      rep(j, 3){
	c  += (n[j] - i) / 3;
      }
      //cout << c << endl;
      res = max(res, c);
    }
    cout << res << endl;
  }
  return 0;
}