#include <iostream>
using namespace std;

int main(){
  int a, b, c, x, y;

  cin >> a >> b >> c >> x >> y;
  if(x>y){
    cout << min(min(a*x+b*y, a*(x-y)+c*2*y), c*2*x) << endl;
  }else{
    cout << min(min(a*x+b*y, b*(y-x)+c*2*x), c*2*y) << endl;
  }
}