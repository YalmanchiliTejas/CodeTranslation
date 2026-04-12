#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int j = a*x+b*y;
  int k = (x > y)? (x-y)*a + 2*c*y : (y-x)*b + 2*c*x;
  int l = (x > y)? x*2*c : y*c*2;
  cout << min({j, k ,l}) << endl;
}
