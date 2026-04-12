#include <iostream>
#include <cstdio>
using namespace std;

int main() {
  int a, b;

  cin >> a >> b;

  cout << "a ";

  if(a > b) putchar('>');
  else if(a < b) putchar('<');
  else cout << "==";

  cout << " b" << endl;
}