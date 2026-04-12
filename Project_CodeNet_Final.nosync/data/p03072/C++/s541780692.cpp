#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int main () {
  cin.tie(0);
  int n;
  cin >> n;
  int h[n];
  for (int i = 0; i < n; i++) cin >> h[i];
  
  int see = 0;
  int maxh = 0;
  
  for (int i = 0; i < n; i++) {
    if (maxh <= h[i]) {
      see++;
      maxh = h[i];
    }
  }
  
  cout << see << "\n";
}