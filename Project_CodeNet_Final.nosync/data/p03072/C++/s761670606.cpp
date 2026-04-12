#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,s,n) for(int i = (s); i < (n); i++)
#define all(v) v.begin(), v.end()

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  ll high = 0;
  ll ans = 0;
  
  vector<int> h(n);
  rep(i, 0, n) {
    cin >> h.at(i);
    if(h.at(i) >= high) {
      high = h.at(i);
      ans++;
    }
  }
  
  cout << ans << "\n";

}
