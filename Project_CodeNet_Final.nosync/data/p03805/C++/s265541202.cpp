#include "stdio.h"
#include <queue>
#include <set>
#include <string.h>
using namespace std;

int N, M;
int a[28], b[28];
struct para{
  set<int> s;
  int n;
};
void solve(){
  int res = 0;
  queue<para> que;
  para p;
  p.n = 1;
  for(int i=1; i<N; i++){
    p.s.insert(i+1);
  }
  que.push(p);

  while(que.size()){
    para pp = que.front(); que.pop();
    if(pp.s.empty()){
      res++;
      continue;
    }
    for(int i=0; i<M; i++){
      int next;
      if(a[i] == pp.n)  next = b[i];
      else if(b[i] == pp.n) next = a[i];
      else continue;
      set<int>::iterator ite = pp.s.find(next);
      if(ite != pp.s.end()){
        para np;
        np.s = pp.s;
        np.n = next;
        np.s.erase(next);
        que.push(np);
      }
    }
  }
  printf("%d\n", res);


}

int main(){

  scanf("%d %d", &N, &M);
  for(int i=0; i<M; i++){
    scanf("%d %d", &a[i], &b[i]);
  }

  solve();

  return 0;
}
