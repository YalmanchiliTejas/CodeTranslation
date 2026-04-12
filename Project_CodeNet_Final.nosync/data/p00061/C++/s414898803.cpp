#include <cstdio>
int p[111];
int r[33];
int main(void){
  int a,b;
  while(~scanf("%d,%d",&a,&b)){
    if(!a && !b) break;
    p[a] += b;
    r[b] = 1;
  }

  for(int i = 30; i >= 0; i--){
    r[i] += r[i+1];
  }

  while(~scanf("%d",&a)){
    printf("%d\n",r[p[a]]);
  }
}