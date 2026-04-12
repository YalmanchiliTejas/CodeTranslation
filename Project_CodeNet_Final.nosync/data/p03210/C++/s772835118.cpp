#include <iostream>
using namespace std;

int main(){
  int x;
  cin >> x;
  switch(x){
    case 3:
    case 5:
    case 7:
      cout << "YES\n";break;
    default:
      cout << "NO\n";break;
  }
  return 0;
}