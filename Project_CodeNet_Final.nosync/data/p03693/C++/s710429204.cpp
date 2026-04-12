#include<iostream>
using namespace std;

int main(){
  int r,g,b;
  int sum;

  cin >> r >> g >> b;

  sum = 100 * r + 10 * g + b;

  if(sum%4==0) cout << "YES" << endl;
  else         cout << "NO"  << endl;

  return 0;
}
