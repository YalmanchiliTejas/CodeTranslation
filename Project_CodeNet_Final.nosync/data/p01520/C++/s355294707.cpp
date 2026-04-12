#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

#define rep(i,j) REP((i), 0, (j))
#define REP(i,j,k) for(int i=(j);(i)<(k);++i)
#define between(a,x,b) ((a)<=(x)&&(x)<=(b))
using namespace std;

int main(){
  int n, t, e, x[128];
  scanf("%d%d%d", &n, &t, &e);
  rep(i, n) scanf("%d", x+i);
  rep(i, n){
    for(int j = 1; x[i] * j <= t+e; j++){
      if(x[i] * j >= t-e){
	printf("%d\n", i+1);
	return 0;
      }
    }
  }

  puts("-1");
  return 0;
}