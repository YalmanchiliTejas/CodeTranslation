#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 1e9;
const ll MOD = 1e9+7;

int main(){
//  ios::sync_with_stdio(false);
//  cin.tie(0);
  ll k,a,b;
  cin >> k >> a >> b;
  if (a >= k) cout << 1 << endl;
  else if (b >= a) cout << -1 << endl;
  else {
    cout << (k-(a-(a-b))+(a-b)-1)/(a-b)*2-1 << endl;
  }
  return 0;
}
