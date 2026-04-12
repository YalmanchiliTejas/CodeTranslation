#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<int> h(n);
  rep(i,n) cin >> h[i];

  int ans = 0;
  rep(i,n){
    bool see = true;
    for(int j=0;j<i;j++){
      if(h[j]>h[i]) see = false;
    }
    if(see) ans++;
  }

  cout << ans << endl;
  
  return 0;
}
