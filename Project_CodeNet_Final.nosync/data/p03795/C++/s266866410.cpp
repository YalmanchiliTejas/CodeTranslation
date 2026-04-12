#include<bits/stdc++.h>
using namespace std;

int main(void){
  int N, x, y;
  cin >> N;
  y = 200 * (N / 15);
  x = 800 * N;
  cout << x - y << "\n";
  return 0;
}
