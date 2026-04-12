#include <stdio.h>
 
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if((a*100+b*10+c)%4) printf("NO\n");
    else printf("YES\n");
    return 0;
}