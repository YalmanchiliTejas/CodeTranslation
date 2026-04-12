#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  
  int sum = 0;
  if(x >= y){
    if(c*2 < a+b){
      sum += c*2*y;
      x -= y;
      if(c*2 < a){
        sum += c*2*x;
      }
      else{
        sum += a*x;
      }
    }
    else{
      sum += a*x + b*y;
    }
  }
  else{
    if(c*2 < a+b){
      sum += c*2*x;
      y -= x;
      if(c*2 < b){
        sum += c*2*y;
      }
      else{
        sum += b*y;
      }
    }
    else{
      sum += a*x + b*y;
    }
  }

  cout << sum << endl;
}

  
