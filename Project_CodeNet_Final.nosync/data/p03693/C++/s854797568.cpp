#include <iostream>
using namespace std;
int r,g,b;
int main(){
  cin >> r >> g >> b;
  cout << ((10*g+b)%4==0? "YES":"NO") << endl;
}