#include <iostream>

using namespace std;

int main(){

  int r,g,b,number;

  while(cin >> r >> g >> b){

    number=(r*100)+(g*10)+b;

    if((number%4)==0) cout << "YES" << endl;

    else cout << "NO" << endl;

  }

  return 0;
}
