#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
#include <map>
using namespace std;

void solve(){
  int n; cin >> n;
  int h[n]; for(int i = 0; i < n; i++) cin >> h[i];
  int i, ans = 0;
  for(i = 0; i < n; i++){
    int j;
    for(j = 0; j < i; j++){
      if(h[j] > h[i]) break;
    }
    if(j == i) ans++;
  }
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}
