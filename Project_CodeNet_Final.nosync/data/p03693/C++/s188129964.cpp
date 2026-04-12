#include<stdio.h>
using namespace std;
int main(){
  int r,g,b;
  scanf("%d %d %d",&r,&g,&b);
  if((100*r + 10*g + b) % 4 == 0) printf("YES\n");
  else printf("NO\n");
}