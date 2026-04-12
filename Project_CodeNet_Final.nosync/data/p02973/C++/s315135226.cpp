#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n,t;
  cin >> n;
  deque<ll> q;
  for(ll i = 0; i < n; ++i){
    cin >> t;
    auto it = lower_bound(begin(q),end(q),t);
    if(it == begin(q)) q.push_front(t);
    else{
      ll idx = it-begin(q);
      q[idx-1] = t;
    }
  }
  cout << q.size();
  return 0;
}