#include<iostream>

using namespace std;

int main(void){
  int r, g, b;
  cin >> r >> g >> b;
  cout << ((2 * g + b) % 4 ? "NO" : "YES") << endl;
  return 0;
}