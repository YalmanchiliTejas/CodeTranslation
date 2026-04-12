#include <iostream>
using namespace std;

int main(){
  int x, y, z;
  cin >> x >> y >> z;
  int num = x / (y + z);
  if(x % (z + y) >= z){
    cout << num << endl;
  }
  else{
    cout << num - 1 << endl;
  }
}