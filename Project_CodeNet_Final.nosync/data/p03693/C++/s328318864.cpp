#include <stdio.h>

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if((100*a+10*b+c)%4) printf("NO");
    else printf("YES");
    return 0;
}