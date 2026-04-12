#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  ll ans = 0;
  vector<int>data(n);
  rep(i,0,n) cin >> data[i];
  sort(data.begin(),data.end());
  rep(i,0,n/2) ans -= 2*data[i];
  rep(i,n/2+1,n) ans += 2*data[i];
  if(n%2 == 1){
    ll ans1 = ans+data[n/2]-data[n/2+1];
    ll ans2 = ans-data[n/2]+data[n/2-1];
    ans = max(ans1,ans2);
  }
  else{
    ans += data[n/2]+data[n/2-1];
  }
  cout << ans << endl;
}