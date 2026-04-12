#include <bits/stdc++.h>
using namespace std;

int main() {
  int oh,ten,one;
  int total;
  cin >> oh >> ten >> one;
  
  total = (oh * 100) + (ten * 10) + one;
  if(total % 4 == 0) cout << "YES";
  else cout << "NO";
}
