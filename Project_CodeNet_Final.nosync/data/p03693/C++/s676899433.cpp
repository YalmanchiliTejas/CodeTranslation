#include <iostream>
using namespace std;

int main(void){
  int x,y,z;
  cin >> x >> y >> z;
  x = 100*x+10*y+z;
  if(x%4==0){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}