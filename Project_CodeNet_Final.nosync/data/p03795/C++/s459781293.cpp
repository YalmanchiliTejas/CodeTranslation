#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,x,y;
  cin >> N;
  x = 800;
  x *= N;
  y = 0;
  if (N >= 15) {
    y = N / 15;
    y *= 200;
  }
  cout << x - y << endl;
}