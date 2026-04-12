#include <iostream>
using namespace std;
int main(void){
  int a,b,c;
  cin >> a >> b >> c;
  
  int n = 10 * b + c;
  
  if(n % 4 == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  
  return 0;
}
