#include <algorithm>
#include <string>
#include <array>
#include <vector>
#include <iostream>

using namespace std;

int main() {

  int n;
  int ans = 0;
  int prev = 0;
  int tmp = 0;

  cin >> n;
  
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    if (tmp >= prev) {
      ans ++;
      prev = tmp;
    } 
  }

  cout << ans << endl;
  
}
