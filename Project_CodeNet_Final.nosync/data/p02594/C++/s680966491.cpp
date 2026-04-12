#include <iostream>
using namespace std;
int main(){
  int x; cin >> x;
  bool flag=false;
  if(x >= 30) flag=true;
  cout << (flag ? "Yes\n" : "No\n");
}
