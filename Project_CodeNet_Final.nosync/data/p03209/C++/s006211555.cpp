#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n;
vector<ll> dep(52), p(52);

ll f(ll a, ll b) {
  if(b == 1 && a == 0) return 1;
  if(b == 1 && a != 0) return 0;
  if(b <= dep.at(a) / 2) return f(a - 1, b - 1);
  if(b == dep.at(a) / 2 + 1) return p.at(a - 1) + 1;
  if(b <= dep.at(a) - 1) return p.at(a - 1) + 1 + f(a - 1, b - dep.at(a - 1) - 2);
  return 2 * p.at(a - 1) + 1;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll x;
  cin >> n >> x;
  
  dep.at(0) = 1;
  p.at(0) = 1;
  for(int i = 1; i < n + 1; i++){
    dep.at(i) = 2 * dep.at(i - 1) + 3;
    p.at(i) = 2 * p.at(i - 1) + 1;
  }
  
  cout << f(n, x) << '\n';
}