#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main() {
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  ll sum;
  if(A+B<=2*C){
      cout << X*A + Y*B;
      return 0;
    }
  else{
    int sa = max(X,Y)-min(X,Y);
    sum += 2*C*min(X,Y);
    int a;
    if(X>Y){
      if(sa*A >= sa*2*C) sum += sa*2*C;
      else sum += sa*A;
    }
    else{
      if(sa*B >= sa*2*C) sum += sa*2*C;
      else sum += sa*B;
    }
  }
  cout << sum;
}