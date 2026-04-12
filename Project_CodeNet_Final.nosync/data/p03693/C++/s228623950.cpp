#include <stdio.h>
#include <queue>
#include <vector>
#include <string>

int main(){

    int r,g,b;
    scanf("%d%d%d", &r,&g,&b);

    int ans = r*100 + g*10 + b;

    if( ans % 4 ) printf ("NO\n");
    else printf ("YES\n");


    return 0;

}
