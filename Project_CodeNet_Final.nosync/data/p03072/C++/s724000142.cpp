#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a;
  int cnt = 1, check;
  cin >> check;
  for (int i = 0; i < n-1; i++) {
    cin >> a;
    if (check <= a) {
      cnt++;
      check = max(check, a);
    }
    
  }
  cout << cnt << endl;
}


