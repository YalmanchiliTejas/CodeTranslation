#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a;
  cin >> a;
  int count = 0;
  count += (a/15)*200;
  cout << a*800-count << endl;
}