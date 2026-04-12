#include<iostream>
using namespace std;
 
int main(void){
  int r,g,b,sum;
  cin >> r >> g >> b;
  sum = 100*r + 10*g + b;
  if(sum % 4 == 0)cout << "YES" << endl;
  else cout << "NO" << endl;
}
