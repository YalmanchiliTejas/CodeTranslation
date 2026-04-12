#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  int y=x/15, count=0;
  while(y>=1) {
    y--;
    count++;
  }
  cout << x*800 - 200*count << endl;
  return 0;
}
