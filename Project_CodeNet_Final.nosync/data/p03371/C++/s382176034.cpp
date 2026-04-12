#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,x,y,sum;
  cin>>a>>b>>c>>x>>y;

  if (a+b>c*2) {
    if (x<y) {
      sum=x*2*c;
      y-=x;
      if (b>c*2) {
	sum+=y*2*c;
      }
      else {
	sum+=y*b;
      }
    }
    else {
      sum=y*2*c;
      x-=y;
      if (a>c*2) {
	sum+=x*2*c;
      }
      else {
	sum+=x*a;
      }
    }
  }  
  else {
    sum=x*a+y*b;
  }

  cout << sum << endl;
  return 0;
}