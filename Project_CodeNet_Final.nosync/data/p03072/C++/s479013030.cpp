#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;


int main() {
  int n;
  cin >> n;
  int mx, ans = 1;
  cin >> mx;
  rep(i,n-1) {
    int x;
    cin >> x;
    if(x<mx) continue; 
    ans++;
    mx = x;
  }
  cout << ans << endl;
  return 0;
}