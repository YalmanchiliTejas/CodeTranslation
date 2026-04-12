#include <stdio.h>

#define MAX(X,Y) ((X)>(Y)?(X):(Y))
#define MIN(X,Y) ((X)<(Y)?(X):(Y))

int main(void){
    int n,x,y;
    
    scanf("%d", &n);
    x = 800*n;
    y = 200*(n / 15);
    printf("%d\n", x-y);
    return 0;
}