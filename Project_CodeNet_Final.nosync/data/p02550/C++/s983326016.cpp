#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  ll n;
  ll x,m;
  cin >> n >> x >> m;

  vector<pair<ll,ll>> ord(m);
  ll a = x;
  ll sum = 0;
  for(ll i = 0; i < n; i++){
    if(ord[a].first){
      ll res = n-i-1;
      ll t = i - ord[a].first;
      ll c = res/t;
      ll sumc = (sum - ord[a].second);
      sum += sumc*c;
      i += c*t;
    }else{
          ord[a].first = i;
          ord[a].second = sum;
    }
    sum += a;
    a = (a*a)%m;
  }
  cout << sum << endl;
}
