#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int x,y,z;
  
  x= 800*N;
  z= N%15;
  y= (N-z)/15*200;
  
  cout << x-y << endl;
  }