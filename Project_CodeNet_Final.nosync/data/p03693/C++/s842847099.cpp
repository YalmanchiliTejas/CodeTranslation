#include <stdio.h>
int main(void){
    int r,g,b,a,ans;
    char buf[256];
    scanf("%d%d%d",&r,&g,&b);
    sprintf(buf,"%d%d",g,b);
    sscanf(buf,"%d",&a) ;
    if(a%4 == 0 || b == 0){
        printf("YES");
    }else{
        printf("NO");
    }
}