#include<iostream>
using namespace std;
int main() {
  int a,n,x,y;
  cin >> n;
  a = n/15;
  x = 800*n;
  y = 200*a;
  cout << x-y << endl;
  return 0;
}