#include<iostream>
using namespace std;
int r, g, b;
int main(){
  cin >> r >> g >> b;
  int n=0;
  n += r; n *= 10;
  n += g; n *= 10;
  n += b;
  if(n % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
  }