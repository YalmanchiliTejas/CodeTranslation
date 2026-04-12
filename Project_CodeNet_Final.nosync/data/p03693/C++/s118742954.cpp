#include <bits/stdc++.h>
using namespace std;

int main(){

  int r, g, b;
  cin >> r >> g >> b;
  int num;
  num = 100 * r + g * 10 + b;
  if (num % 4 == 0){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }

  return 0;
}
