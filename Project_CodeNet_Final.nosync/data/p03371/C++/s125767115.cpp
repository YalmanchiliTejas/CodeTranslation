#include <iostream>
#include <numeric>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>

#define repd(i,a,b); for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define ll long long int
 
 
using namespace std;
int main() {
 int a,b,c,x,y; cin >> a >> b >> c >> x >> y;
  if(a+b <= 2*c){
    cout << a*x+b*y;
    exit(0);
  }
  
  if(x>y){
    if(2*c<a){
      cout << 2*c*x;
      exit(0);
    } else {
      cout << 2*c*y+(x-y)*a;
      exit(0);
    }
  } else {
    if(2*c<b){
      cout << 2*c*y;
      exit(0);
    } else {
      cout << 2*c*x+(y-x)*b;
    }
  }
 return 0;
}