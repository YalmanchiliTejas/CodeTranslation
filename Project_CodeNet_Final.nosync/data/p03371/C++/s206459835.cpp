#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
  
  C *= 2; int64_t sum = 5000 * 2 * pow(10, 5) + 1;
  
  for (int i = 0; i <= max(X, Y); i++) {
    
    int numA = max(0, X - i); int numB = max(0, Y - i);
    
    int64_t tmp = A * numA + B * numB + C * i;
    
    sum = min(sum, tmp);
    
  }
  
  cout << sum << endl;
  
}