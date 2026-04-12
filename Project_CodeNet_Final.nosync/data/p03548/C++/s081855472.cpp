#include <stdio.h>
int main (void){
    int x,y,z,a;
    scanf("%d%d%d",&x,&y,&z);
    x=x-z;
    a=x/(y+z);
    printf("%d\n",a);
    return 0;
}