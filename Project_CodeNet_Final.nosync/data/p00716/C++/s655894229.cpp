#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

int main(){
  int C,M,N,Y,cmd[110],pay[110];
  double per[110];
  int i,j;

  scanf("%d",&M);
  while(M--){
    scanf("%d",&C);
    scanf("%d",&Y);
    scanf("%d",&N);
    REP(i,N) scanf("%d %lf %d",&cmd[i],&per[i],&pay[i]);

    int res = C;
    REP(i,N){
      if(cmd[i] == 1){
        int tmp = C;
        REP(j,Y){
          tmp *= 1.0 + per[i];
          tmp -= pay[i];
        }
        res = max(res,tmp);
      } else {
        int tmp = C;
        int cache = 0;
        REP(j,Y){
          cache += tmp * per[i];
          tmp -= pay[i];
        }
        res = max(res, tmp + cache);
      }
    }
    printf("%d\n",res);
  }

  return 0;
}