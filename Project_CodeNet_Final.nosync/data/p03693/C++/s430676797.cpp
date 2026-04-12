#include <iostream>
using namespace std;

int main(){
  
  int r, g, b;
  cin >> r >> g >> b;
  int c = 100 * r + 10 * g + b;
  if(c % 4 == 0)cout <<"YES"<<endl;
  else cout<<"NO"<<endl;
}