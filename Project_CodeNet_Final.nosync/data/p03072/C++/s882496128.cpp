#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int counter = 0;
  for (int i = 0; i < n; i++) {
    bool flag = true;
    for (int j = 0; j < i; j++) {
      if (a[j] > a[i]) {
        flag = false;
        break;
      }
    }
    if (flag) counter++;
  }
  cout << counter;
}