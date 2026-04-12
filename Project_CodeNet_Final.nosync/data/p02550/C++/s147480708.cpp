#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
    
    // ここから入力
    ll n,ans = 0;
    ll x,m,b = 0,cnt = 0;
    bool lp = false;
    cin >> n >> x >> m;
    vector<ll> aa;
    vector<int> checked(m+1,0);
    
  
    int i = 0;
    while(i < n){
      ans += x;
      checked.at(x)++;
      x = (x*x)%m;
      cnt++;
      if(x == 0) break;
      if(checked.at(x) == 2){
        aa.push_back(x);
        b += x;
        lp = true;
      }
      if(checked.at(x) == 3){
          break;
      }
        i++;
    }
 
    ans -= 3*b;
    if(lp){
      ll c = aa.size();
      n -= (cnt - 3*c);
      ll kakeru = n / c;
      ll amari = n % c;
      ans += b * kakeru;
      REP(i,amari) ans += aa[i];
    }
    
   cout << ans << endl;
   
}
