#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> d;
  rep(i, n){
    auto it = lower_bound(d.rbegin(), d.rend(), a[i]);
    if (it == d.rbegin()){
      d.push_back(a[i]);
    }else{
      --it;
      *it = a[i];
    }
  }
  int ans = d.size();
  cout << ans << endl;
  return 0;
}
