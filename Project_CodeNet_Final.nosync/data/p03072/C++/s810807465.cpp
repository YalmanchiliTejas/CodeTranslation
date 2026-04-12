#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n;
  cin >> n;
  int m;
  cin >> m;
  int ans = 1;
  rep(i,n-1){
    int x;
    cin >> x;
    if(m <= x){
      m = x;
      ans++;
    }
  }
  cout << ans;
      
  return 0;
}



