#include <iostream>
using namespace std;

int main() {
  int k,g[100000],x,total = 0,f,rank,rankswitch = 0;
  int order[100000] = {1};
  while(scanf("%d,%d",&k,&f) == 2) {
    g[k] = f;
    total++;
    if((k == 0) && (f == 0))
      break;
  }
  rank = 1;
  for(int j=0;j<31;j++) {
    for (int i=1;i<total;i++){
      if(g[i] == 30 - j) {
        order[i] = rank;
        rankswitch = 1;
      }
      if((rankswitch == 1) && (i == total-1)) {
        rank++;
        rankswitch = 0;
      }
    }

  }

  while(scanf("%d",&x) == 1) {
    cout << order[x] << endl;
  }

}