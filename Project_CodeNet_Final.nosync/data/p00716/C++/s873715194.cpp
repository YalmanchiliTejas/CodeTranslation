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
  int d;
  scanf("%d", &d);
  while(d--){
    int m, y, n, res = 0;
    scanf("%d%d%d", &m, &y, &n);
    int k, c;
    double rate;
    rep(i, n){
      int money = m;
      scanf("%d%lf%d", &k, &rate, &c);
      if(k){
	rep(i, y){
	  money +=  money * rate;
	  money -= c;
	}
      }else{
	int sum = 0;
	rep(i, y){
	  sum += money * rate;
	  money -= c;
	}
	money += sum;
      }
      //      printf("%d\n", money);
      res = max(res, money);
    }
    printf("%d\n", res);
  }
  return 0;
}