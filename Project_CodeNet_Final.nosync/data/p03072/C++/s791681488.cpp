#include <iostream>
#include <cstring>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = 0;
  int tmp = 0;
  for(int i = 0; i < n; i++) {
    int h;
    cin >> h;
    if(tmp <= h) {
      tmp = h;
      ans++;
    }
  }

  cout << ans << endl;
  
}
