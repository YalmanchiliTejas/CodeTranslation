#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

int main(){
  long A,B,C,X,Y;
  long p[4];
  cin >> A >> B >> C >> X >> Y;
  p[0] = C * max(X,Y) * 2;
  if(X >= Y){
    p[1] = C * Y * 2 + A * (X-Y);
  }else{
    p[1] = C * X * 2 + B * (Y-X);
  }
  p[2] = A * X + B * Y;
  sort(p,p+3);
  cout << p[0] << endl;
}