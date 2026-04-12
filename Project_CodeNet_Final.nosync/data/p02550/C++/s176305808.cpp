#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  ll n, x, m;  cin >> n >> x >> m;
  if(m==1){
    cout << "0\n";
    return 0;
  }

  vector<ll> val(m);
  for (int i = 0; i < m; ++i){
    val[i] = x;
    x = 1LL*x*x%m;
  }
  if(n<=m){
    cout << accumulate(val.begin(), val.begin()+n, 0LL) << "\n";
    return 0;
  }

  vector<ll> rep;
  rep.push_back(val[m-1]);
  int i = m-2;
  while(i>=0 and val[i]!=val[m-1]){
    rep.push_back(val[i]);
    i--;
  }
  reverse(rep.begin(), rep.end());
  ll sz = rep.size();
  ll ans = accumulate(val.begin(), val.begin()+m, 0LL);
  n -= m;
  ll d = n/sz;
  ll sum = accumulate(rep.begin(), rep.end(), 0LL);
  ans += sum*d;
  n -= d*sz;
  for (int i = 0; i < n; ++i){
    ans += rep[i];
  }
  cout << ans << "\n";
  return 0;
}