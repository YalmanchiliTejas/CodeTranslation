#include <iostream>
using namespace std;
#define MIN(X,Y) ((X)<(Y)?(X):(Y))

int main(void){
  int a,b,c,x,y;
  
  cin >> a >> b >> c >> x >> y;
  if (a+b<=c*2){
    cout << (a*x + b*y) << endl;
  } else {
    if (x<y){
      cout << (x*2*c+(y-x)*MIN(b,2*c)) << endl;
    } else {
      cout << (y*2*c+(x-y)*MIN(a,2*c)) << endl;
    }
  }
  return 0;
}