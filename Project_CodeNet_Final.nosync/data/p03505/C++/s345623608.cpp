#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  ll k, a, b;
  cin >> k >> a >> b;
  if(k > a and b >= a) cout << -1 << endl;
  else if(a >= k) cout << 1 << endl;
  else {
    ll n = (k-b-1)/(a-b);
    cout << 2*n + 1 << endl;
  }
  return 0;
}
