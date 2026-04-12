#include <stdio.h>

int main(void){
int r;
int g;
int b;
int goukei;

scanf("%d%d%d",&r,&g,&b);

goukei = ((100*r)+(10*g)+b)%4;

if(goukei==0){
printf("YES");
}else{
printf("NO");
}
}