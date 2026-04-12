#include <iostream>
using namespace std;

int main() {
  int n, h[110];
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> h[i];
  int res = 1;
  
  for (int i = 1; i < n; ++i) {
    
      bool big = false;
      for (int j = 0; j < i; ++j) {
        if (h[i] < h[j]) big = true;
      }
      if (big) continue;
      ++res;
    
  }
  cout << res << endl;
}
