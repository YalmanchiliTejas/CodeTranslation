#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int X, Y, Z; cin >> X >> Y >> Z;

  int Ans = 0;
  int temp = Z;
  while(true) {
    temp += Y+Z;
    if ( temp<X )  {Ans++;}
    if ( temp==X ) {Ans++; break;}
    if ( temp>X )  {break;}
  }

  cout << Ans << endl;
}
