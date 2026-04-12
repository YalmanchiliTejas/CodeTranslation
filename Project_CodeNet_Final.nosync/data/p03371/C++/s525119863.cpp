#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,X,Y;
  cin >> A>>B>>C>>X>>Y;
  int sum=0;
  if(A+B>2*C){
    int m = min(X,Y);
    sum += m*C*2;
    int res = max(X,Y) - m;
    if(X>Y){
      if(A>C*2) sum += res*C*2;
      else sum += res*A;
    }
    else{
      if(B>C*2) sum += res*C*2;
      else sum += res*B;
    }
  }
  else{
    sum += A*X+B*Y;
  }
cout << sum << endl;
}
