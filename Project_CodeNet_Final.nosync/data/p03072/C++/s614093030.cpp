#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const ll inf=1000000000007;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i,0,n) cin >> h[i];
  ll val=h[0];
  int ans=1;
  rep(i,1,n){
    if(h[i]>=val){
      ans++;
      val=h[i];
    }
  }
  cout << ans << endl;
  return 0;
}