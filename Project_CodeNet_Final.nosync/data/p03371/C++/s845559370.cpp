#include<iostream>
#include<algorithm>

using namespace std;

int main(){
  int a, b, c, x, y, min;
  cin >> a >> b >> c >> x >> y;
  if(a+b < 2*c){
    cout << a*x + b*y << endl;
  }
  else {
    if(x>=y){
      if(a>2*c&&a*x+b*y>2*c*x) cout << 2*c*x << endl;
      else if(a*x+b*y>2*c*y+a*(x-y)) cout << 2*c*y+a*(x-y) <<endl;
      else cout << a*x+b*y << endl;
    }
    else{
      if(b>2*c&&a*x+b*y>2*c*x) cout << 2*c*y << endl;
      else if(a*x+b*y>2*c*x+b*(y-x)) cout << 2*c*x+b*(y-x) <<endl;
      else cout << a*x+b*y << endl;
    }
  }
}