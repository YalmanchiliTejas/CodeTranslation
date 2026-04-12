#include<bits/stdc++.h>
using namespace std;

int main(void){
  int r, g, b;
  int value;
  cin >> r >> g >> b;
  value = 100 * r + 10 * g + b;
  if(value % 4 == 0)
    cout << "YES" << "\n";
  else
    cout << "NO" << "\n";
  return 0;
}
