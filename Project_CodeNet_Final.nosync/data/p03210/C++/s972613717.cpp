#include <stdio.h>
int main(void){
    int X;
    scanf("%d",&X);
    
    switch(X){
        case 3:
        case 5:
        case 7: puts("YES"); break;
    default: puts("NO");
    }
}
