#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int t = n / 15;
  cout << 800 * n - t * 200 << endl;
}