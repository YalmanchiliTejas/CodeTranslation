#include <iostream>
#include <cstring>
#include <map>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <queue>
#include <list>
#include <numeric>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <math.h>
#include <stack>
#include <climits>
#include <bitset>

using namespace std;
typedef long long ll;

int gcd(int x, int y) {
  if (x < y) swap(x, y);
  while (y > 0) {
    int r = x % y;
    x = y;
    y = r;
  }
  return x;
}

//for(int i = ; i < ; i++){}

int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int sum = 0;
  if(a+b>2*c){
    if(x>y){
      sum=min(2*c*x,2*c*y+a*(x-y));
    }
    else{
      sum=min(2*c*y,2*c*x+b*(y-x));
    }
  }
  else{
    sum=a*x+b*y;
  }
  cout<<sum<<endl;
  return 0;
}


