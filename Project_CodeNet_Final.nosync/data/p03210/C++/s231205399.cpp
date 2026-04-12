#include <iostream>
using namespace std;
int main(){
  int x;
  cin >> x;
  if(x % 2 && (x % 8)  > 1){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}