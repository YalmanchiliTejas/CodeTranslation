#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int t,j=0,ans=0;
  for(int i=0; i<n; i++) {
    cin >> t;
    if(j <= t) {
      j = t;
      ans++;
    }
  }
  cout << ans << endl;
}