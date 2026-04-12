#include<stdio.h>

int main(void) {
    int r,g,b;
    scanf("%d%d%d",&r,&g,&b);
    int result = 100*r+10*g+b;
    if (result%4 == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}
