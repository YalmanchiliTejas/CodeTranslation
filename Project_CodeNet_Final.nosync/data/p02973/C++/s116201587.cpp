#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<(n);++i)

signed main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<int> d;
  rep(i,n){
    auto p=lower_bound(d.rbegin(),d.rend(),a[i]);
    if(p==d.rbegin()){
      d.push_back(a[i]);
    } else{
      p--;
      *p= a[i];
    }
  }
  int ans=d.size();
  cout << ans << endl;
  return 0;
}
