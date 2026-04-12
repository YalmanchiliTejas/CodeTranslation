#include <iostream>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  int maxh = 0;
  int ans = 0;
  rep(i, n){
    int h;
    cin >> h;
    if (h >= maxh){
      ans++;
      maxh = h;
    }
  }
  cout << ans << endl;
  
  return 0;
}