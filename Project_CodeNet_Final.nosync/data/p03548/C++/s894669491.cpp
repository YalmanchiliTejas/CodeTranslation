#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
int main() {
  int X,Y,Z;
  cin >> X >> Y >> Z;
  
  int space1 = Y + Z;
  int capa = X / space1;
  
  if (X % space1 >= Z) {
    cout << capa << endl;
  }
  else {
    cout << capa - 1 << endl;
  }
}