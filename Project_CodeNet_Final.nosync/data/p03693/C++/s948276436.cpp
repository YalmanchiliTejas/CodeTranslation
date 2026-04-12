#include <iostream>
using namespace std;
int main(){
  int n=0;
  int m;
  cin >>m;
  n += m*100;
  cin >>m;
  n += m*10;
  cin >>m;
  n += m;
  
  if(n%4==0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
