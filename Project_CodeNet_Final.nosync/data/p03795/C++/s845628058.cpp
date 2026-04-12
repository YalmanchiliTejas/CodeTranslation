#include <bits/stdc++.h>
using namespace std;

int main() {
  int eat;
  int get = 0;
  
  cin >> eat;
  get = (eat / 15) * 200;
  cout << 800 * eat - get;
}
