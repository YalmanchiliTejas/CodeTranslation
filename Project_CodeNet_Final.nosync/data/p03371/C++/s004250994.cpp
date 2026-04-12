#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll X,Y;
  int A,B,C;
  cin >> A >> B >> C >> X >> Y;
  ll min_cost = 1.0e10;
  for(ll u=0;u<=max(X*2,Y*2);u=u+2){
    ll s,t;
    if(X-u/2 <= 0){
      s = 0;
    }else{
      s = X-u/2;
    }
    if(Y-u/2 <= 0){
      t = 0;
    }else{
      t = Y-u/2;
    }
    ll cost = A*s+B*t+C*u;
    //cout << cost << endl;
    //cout << s << " " << t << " " << u << endl;
    if(cost < min_cost){
      min_cost = cost;
    }
  }
      
  cout << min_cost << endl;
  return(0);
}