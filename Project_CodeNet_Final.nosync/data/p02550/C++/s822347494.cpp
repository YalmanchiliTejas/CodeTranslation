#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, x, m;
  cin >> n >> x >> m;
  vector<pair<bool, int>> samefirst(m);
  rep(i,m) samefirst[i].first = false;
  vl a(m);
  a[0] = x;
  samefirst[a[0]].first = true;
  samefirst[a[0]].second = 0;
  int end = -1, aend = -1;
  for(int i=1; i<n; i++){
    a[i] = a[i-1] * a[i-1] % m;
    if(samefirst[a[i]].first){
      end = i;
      aend = a[i];
      break;
    }
    else{
      samefirst[a[i]].first = true;
      samefirst[a[i]].second = i;
    }
  }
  ll ans = 0;
  if(end != -1){
    ll sum = 0;
    ll first = samefirst[aend].second;
    for(int i=first; i<end; i++) sum += a[i];
    rep(i,first) ans += a[i];
    ll rest1 = n - first;
    ans += rest1 / (end - first) * sum;
    ll rest2 = rest1 % (end - first);
    for(int i=first; i<first + rest2; i++) ans += a[i];
  }
  else rep(i,n) ans += a[i];
  cout << ans << endl;
}
