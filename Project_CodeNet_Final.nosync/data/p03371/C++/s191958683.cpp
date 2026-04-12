#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int Sum = 0;

  if(a + b <= 2 * c){
    Sum = a * x + b * y;
  }
  else if(x < y){
    Sum = 2 * x * c + (y - x) * min(b,2*c);
  }
  else{
    Sum = 2 * y * c + (x - y) * min(a,2*c);
  }

  cout << Sum << endl;

}
