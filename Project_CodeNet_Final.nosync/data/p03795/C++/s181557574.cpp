#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int x,y;
  x = 800 * N;
  if(N >=90) y = 1200;
  else if(N >=75) y = 1000;
  else if(N >=60) y = 800;
  else if(N >=45) y = 600;
  else if(N >=30) y = 400;
  else if(N >=15) y = 200;
  else y = 0;
  
  cout << x - y << endl;
}