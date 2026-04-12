#include <iostream>
using namespace std;

int main(){

  int r,g,b,val;
  cin >> r >> g >> b;
  val = 100 * r + 10 * g + b;
  if(val%4 == 0){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}
