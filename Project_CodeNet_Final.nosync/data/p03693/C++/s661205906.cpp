#include <stdio.h>
#include <stdlib.h>

int main() {
    int r,g,b;
    /*char R,G,B;
    scanf("%c %c %c",&R,&G,&B);*/
    int s=0;
    while( scanf("%d%d%d",&r,&g,&b)!=EOF) {
        s=r*100+g*10+b;
        if(s%4==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
return 0;
}