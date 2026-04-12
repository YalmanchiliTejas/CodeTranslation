#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
using namespace std;
int main(){
  long long a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  c *= 2;
  if (a + b <= c){
    cout<<a * x + b * y;
    return 0;
  }
  if ((a <= c) and (b <= c)){
    if (x >=y) cout<<y * c + (x - y) * a;
    else cout<<x * c + (y - x)*b;
    return 0;
  }
  if ((a >= c) and (b >= c)){
  	if (x >= y) cout<<x * c;
  	else cout<< y * c;
  	return 0;
  }
  if ((a >= c) and (b <= c)){
  	if (y >= x) cout<<x * c + (y - x)*b;
  	else cout<<x * c;
  	return 0;
  }
  if ((a <= c) and (b >= c)){
  	if (x >= y) cout<<y * c + (x - y)*a;
  	else cout<<y * c;
  	return 0;
  }
}