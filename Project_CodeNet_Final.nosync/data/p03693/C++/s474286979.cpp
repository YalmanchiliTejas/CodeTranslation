#include <iostream>
using namespace std;

int main(){

  int r, g, b, tmp;

  cin >> r >> g >> b;

  tmp = r * 100 + g * 10 + b;

  if(tmp % 4 == 0){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}
