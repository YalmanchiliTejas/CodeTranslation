#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,x = 0,y = 0;

  cin >> N;

  x += 800 * N;
  y += (N / 15) * 200;

  cout << x - y << endl;
}
