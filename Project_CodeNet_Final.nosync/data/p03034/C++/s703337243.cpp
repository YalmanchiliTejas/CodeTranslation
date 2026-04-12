#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using E = tuple<ll, int, ll>;
const ll inf = numeric_limits<ll>::max()/3;
const ll mod = 1e9 + 7;

ll dp[1000][1000];
ll s[100010];

int main(void){
  int n;
  cin >> n;
  for(int i = 0;i < n;++i){
    cin >> s[i];
  }
  ll res = 0;
  for(int d = 1;d <= n-1;++d){
    ll calc = 0;
    for(int k = 1;d < (n-1) - k*d;++k){
      calc += s[(n-1) - k*d];
      calc += s[k*d];
      if((n-1) % d == 0 && (n-1)/d <= 2*k){
        continue;
      }
      res = max(res,calc);
    }
  }
  cout << res << endl;
  return 0;
}
