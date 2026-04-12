#include <iostream>
using namespace std;

int main(){
  int X,Y,Z;  cin >> X >> Y >> Z;

  int enb = 0;

  for(int i = 1;;i++){
    if(i * Y + (i + 1) * Z <= X)enb = i;
    else break;
  }

  cout << enb << endl;
}