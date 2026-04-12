#include <iostream>
using namespace std;

int a,b,c;

int main(){
  cin >> a >> b >> c;
  int result;

  result = 100*a+10*b+c;
  (result%4)?(cout << "NO" << endl):(cout << "YES" << endl);
  return 0;
}
