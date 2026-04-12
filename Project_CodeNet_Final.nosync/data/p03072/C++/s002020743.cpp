#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i,n) cin >> h[i];
  int count = 0;
  rep(i,n) {
    bool flag = true;
    rep(j,i){
      if(h[i]<h[j]){
        flag = false;
        break;
      }
    }
    if(flag) ++count;
  }
  cout << count << endl;
  return 0;
}
