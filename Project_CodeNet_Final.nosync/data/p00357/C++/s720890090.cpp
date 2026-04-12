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
#define SIZE 300010


int main(){
  int n, d[SIZE];

  scanf("%d", &n);

  for(int i=0;i<n;i++) scanf("%d", d+i);


  for(int p=0;p<2;p++){
    int r  = 0;

    for(int i=0;i<n;i++){
      if(i > r){
        puts("no");
        return 0;
      }
      r = max(r, d[i]/10 + i);
    }

    reverse(d, d+n);
  }

  puts("yes");
  
  return 0;
}

