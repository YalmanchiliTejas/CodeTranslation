#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  cin >> a;
  b = (int) floor((double)a/15);
  cout << 800*a-200*b;
  return 0;
}