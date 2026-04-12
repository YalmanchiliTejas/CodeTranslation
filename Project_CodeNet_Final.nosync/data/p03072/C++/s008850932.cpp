#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
  int n;
  cin >> n;
  int h[n];
  for(int i = 0; i < n; i++) cin >> h[i];
  int ans = 0;
  int maxh = h[0];
  for(int i = 0; i < n; i++){
    if(h[i] >= maxh){
      ans++;
      maxh = h[i];
    }
  }
  cout << ans << endl;
  return 0;
}
