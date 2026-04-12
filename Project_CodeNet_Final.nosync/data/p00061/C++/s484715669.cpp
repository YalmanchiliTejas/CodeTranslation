#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <cstring>
#include <functional>

using namespace std;

#define rep(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(itr,c) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
inline int in(){ int x; scanf("%d",&x); return x;}

typedef pair<int,int> P;

P data[10000];

int main(){
  int i,j,k;
  int a,b;

  for(i = 0; ; i++){
    scanf("%d,%d",&a,&b);
    if(a == 0 && b == 0) break;
    data[i] = P(b,a);
  }

  int n = i;
  sort(data,data+n,greater<P>());
//  rep(i,n) cout << data[i].second << "," << data[i].first << endl;

  int team;
  while(scanf("%d",&team) != EOF){
    int res = 1;
    for(i = 0; i < n; i++){
      if(i-1 >= 0 && data[i].first < data[i-1].first) res++;
      if(data[i].second == team){
        printf("%d\n",res);
        break;
      }
    }
  }

  return 0;
}