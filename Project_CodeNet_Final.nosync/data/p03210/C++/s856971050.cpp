#include <iostream>
using namespace std;
int main(){
  int x;
  cin >> x;
  if((x>2)&&(x<8)&&(x%2)){
    cout << "YES\n";
  }else{
    cout << "NO\n";
  }
  return 0;
}
