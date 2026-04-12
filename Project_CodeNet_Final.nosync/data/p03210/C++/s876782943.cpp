#include <iostream>
using namespace std;

int main(){
  int X;
  cin >> X;
  bool can = false;
  if (X==3 || X==5 || X==7) can = true;
  if(can) cout << "YES" << endl;
  else cout << "NO" << endl;
}