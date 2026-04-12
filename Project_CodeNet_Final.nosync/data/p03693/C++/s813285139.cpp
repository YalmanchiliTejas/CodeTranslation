#include <iostream>
using namespace std;
int main(){
  int a,b,c;                                                                          cin >> a >> b >> c;
  int x = a*100+b*10+c;
  if(x%4==0) cout << "YES" << "\n";
  else cout << "NO" << "\n";
  return 0;
}