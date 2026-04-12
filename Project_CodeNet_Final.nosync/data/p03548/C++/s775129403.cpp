#include <cstdio>
#include <cmath>
using namespace std;
int main(void){
  int x,y,z,t;
  scanf("%d%d%d",&x,&y,&z);
  printf("%d\n",(t=floor((x-z)/(y+z)))>0?t:0);
  return 0;
}