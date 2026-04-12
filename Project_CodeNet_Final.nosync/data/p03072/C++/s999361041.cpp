#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,max_h=0,ans;
  cin >> n;
  vector<int> h(n);
  for(int i=0;i<n;i++) cin >> h[i];
  for(int i=0;i<n;i++) {
    if(max_h<=h[i]) {
      ans++;
      max_h=h[i];
    };
  };
  cout << ans << endl;
}