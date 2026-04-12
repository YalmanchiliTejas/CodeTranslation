#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))


int main() {
  ll N;
  scanf("%llu\n",&N );
  std::vector<ll> v(N);
  for (size_t i = 0; i < N; i++) {
    scanf("%llu\n",&v[i] );
  }
  std::sort(v.begin(),v.end());

  ll upper=0;
  ll down=0;

  if(N%2==0){

    for (size_t i = 0; i < N/2; i++) {
      down +=v[i]*2;
    }
    down -= v[N/2-1];

    for (size_t i = N/2; i < N; i++) {
      upper +=v[i]*2;
    }
    upper -= v[N/2];

  }else{

    if(v[(N+1)/2]-v[(N+1)/2-1] < v[(N+1)/2-1]-v[(N+1)/2-2]){
      for (size_t i = 0; i < (N+1)/2-1; i++) {
        down +=v[i]*2;
      }

      for (size_t i = (N+1)/2-1; i < N; i++) {
        upper +=v[i]*2;
      }
      upper-= v[(N+1)/2-1];
      upper-= v[(N+1)/2];

    }else{
      for (size_t i = 0; i < (N+1)/2; i++) {
        down +=v[i]*2;
      }
      down -= v[(N+1)/2-1];
      down -= v[(N+1)/2-2];

      for (size_t i = (N+1)/2; i < N; i++) {
        upper +=v[i]*2;
      }
    }
  }

  printf("%llu\n",upper-down );
  return 0;
}
