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
#include <unordered_map>
#include <unordered_set>

#include <complex>

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
  int n;
  ll a[51];

  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%lld",a+i);
  }

  bool flag = true;
  ll ans = 0;
  while(flag){
    ll calc = 0;
    ll memo[50];
    
    for(int i=0;i<n;i++){
      memo[i] = a[i]/n;
      calc += a[i]/n;
      a[i] %= n;
    }

    for(int i=0;i<n;i++){
      a[i] += calc - memo[i];
    }

    flag = calc > 0;
    ans += calc;
  }

  printf("%lld\n",ans);
  
  return 0;
}
