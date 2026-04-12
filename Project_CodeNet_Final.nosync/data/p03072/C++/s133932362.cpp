#include <bits/stdc++.h>
using namespace std;

int main() {
  int mx=0, ans=0;
  int n;
  cin >> n;
  for(int i=0; i<n; i++) {
    int a; cin>>a;
    if(a>=mx) {
      ans++;
      mx=a;
    }
  }
  cout << ans << endl;
  return 0;
}