#include <iostream>
#include <vector>

using namespace std;

int main(){
  int X, Y, Z;
  cin >> X >> Y >> Z;
  
  int tmp = 0;
  for(int i = 1; i <= (X + Y - 1) / Y; i++){
    if(i * Y + (i + 1) * Z > X){
      tmp = i - 1;
      break;
    }
  }
  cout << tmp;
}
