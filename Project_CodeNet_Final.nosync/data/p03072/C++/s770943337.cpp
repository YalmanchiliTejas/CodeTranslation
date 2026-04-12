#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int n;
  cin >> n;
  int ans = 1;
  int h[n];
  rep(i,n) cin >> h[i];
  int high = h[0];
  for(int i =1; i<n; i++){
    if(h[i] >= high){
      ans++;
      high = h[i];
    }
  }
  cout << ans << endl;
}
    