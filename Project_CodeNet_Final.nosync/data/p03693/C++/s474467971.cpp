#include <iostream>
using namespace std;
int main(){
  int r,g,b;
  cin >> r >> g >>b;
  cout << ((g * 10 + b) % 4 ? "NO" : "YES") << endl;
}