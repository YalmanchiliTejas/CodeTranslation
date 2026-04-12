#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100010


int main(){
  int n, q;
  int st, t,k;
  
  scanf("%d%d", &n, &q);

  st = 0;
  for(int i=0;i<q;i++){
    scanf("%d%d", &t, &k);
    if(t == 0){
      printf("%d\n", (st + k - 1)%n + 1);
    }else{
      st = (st+k)%n;
    }
  }
  
  return 0;
}

