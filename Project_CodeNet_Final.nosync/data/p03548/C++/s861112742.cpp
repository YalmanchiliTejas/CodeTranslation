#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  int answer = 0;
  
  for (int i = 0; i*Y+(i+1)*Z <= X; i++) answer = i;
  cout << answer << endl;
  }