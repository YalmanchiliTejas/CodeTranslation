#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 10000


int main(){
  int n,k;
  double ans;
  
  cin >> n >> k;

  ans = 1 * 1 * sin(2*M_PI/n) * n/2;
  
  if(k > 1){
    double a = sqrt(2 * (1 - cos(2*M_PI/n)));
    ans -= (tan(M_PI/n*(k-1)) * a / 2) * a / 2 * n;
  }
  
  printf("%.10lf\n",ans);
  
  return 0;
}