#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
  int X,Y,Z;
  cin >> X >> Y >> Z;
  
  int can = Y + Z;
  int capa = X / can;
  int space = X % can;
  
  if (space >= Z) {
    cout << capa << endl;
  }
  else {
    cout << capa - 1 << endl;
  }
}