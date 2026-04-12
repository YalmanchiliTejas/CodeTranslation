#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
 
int main() {
  int n;
  cin >> n;
  vector<int>h(n);
  rep(i,n) cin >> h[i];
  
  int res = 0;
  int max_hight = 0;
  
  rep(i,n){
    max_hight = max(max_hight, h[i]);
    if(h[i] >= max_hight) ++res;
  }
  
  cout << res << endl;
  return 0;
}
