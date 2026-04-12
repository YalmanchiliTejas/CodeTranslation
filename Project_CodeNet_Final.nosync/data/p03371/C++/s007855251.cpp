#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  if (a+b <= 2*c){
    cout << a*x+b*y << endl;
  }
  else{
    if (x >= y){
        cout << min(2*c*y+(x-y)*a,2*c*x)  << endl;
    }
    else if (x < y){
        cout << min(2*c*x+(y-x)*b,2*c*y) << endl;
    }
  }
}

