#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, h;
  cin >> n;
  
  int mxh = 0, ans = 0;
  
  for(int i=0; i<n; i++){
    cin >> h;
    if(mxh <= h){
      mxh = h;
      ans++;
    }
  }
  cout << ans <<endl;
}