#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int sum = 0;
  int hMax = 0;
  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    
    if (hMax <= h) {
      sum++;
      hMax = h;
    }
  }
  
  cout << sum << endl;
  return 0;
}