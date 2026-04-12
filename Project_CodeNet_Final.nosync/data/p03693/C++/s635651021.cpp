#include <bits/stdc++.h>
using namespace std;

int r, g, b;

void inin (){
  cin >> r >> g >> b;
}

void judge(){
  int a;
  a = r*100 + g*10 + b;
  a%4 == 0 ? cout << "YES" << endl : cout << "NO" << endl;
}

int main (){
  inin();
  judge();
  return 0;
}

