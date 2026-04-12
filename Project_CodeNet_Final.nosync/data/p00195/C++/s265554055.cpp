#include <bits/stdc++.h>
using namespace std;

int main() {
  while(1) {
    int maxi = -1, index;
    for(int i = 0, a, b; i < 5; ++i) {
      cin >> a >> b;
      if(a == 0 && b == 0) return 0;
      if(maxi < a+b) {
        maxi = a+b;
        index = i;
      }
    }
    cout << (char)('A'+index) << " " << maxi << endl;
  }
  return 0;
}