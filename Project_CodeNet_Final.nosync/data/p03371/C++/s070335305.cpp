#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <iterator>
#include <math.h>
#include <cstdlib>
#include <cmath>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define dump(x)  cerr << #x << " = " << (x) << endl;
using namespace std;
int main(){
  int A,B,C,D,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int cost = 0;
  if(A+B >= 2 * C){
    int cost1 = 0,cost2 = 0;
    cost1 += min(X,Y) * C * 2;
    if(X < Y){
      cost1 += (Y-X)* B;
    }else{
      cost1 += (X-Y)* A;
    }
    cost2 = max(X,Y)*C *2;
    cost = min(cost1,cost2);
  }else{
    cost = X * A + Y * B;
  }
  cout << cost << endl;
  return 0;
}