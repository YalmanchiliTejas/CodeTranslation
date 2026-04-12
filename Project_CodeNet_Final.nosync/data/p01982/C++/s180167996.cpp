#include <bits/stdc++.h>

int main() { 
  for(;;) { 
    int n, l, r; 
    std::cin >> n >> l >> r; 
    if (n == 0 && l == 0 && r == 0) { break; } 
    std::vector<int> xs(n); 
    for(int i = 0; i < n; ++i) std::cin >> xs[i]; 
    int res = 0; 
    for(int y = l; y <= r; ++y) {
      bool flag = false;
      for(int i = 0; i < n; ++i) { 
        if (y % xs[i] == 0) { 
          if (i % 2 == 0) { 
            res += 1; 
          }
          flag = true;
          break;
        }
      }
      if (!flag) {
        if (n % 2 == 0) {
          res += 1;
        }
      }
    }    
    printf("%d\n", res); 
  } 
}
 

