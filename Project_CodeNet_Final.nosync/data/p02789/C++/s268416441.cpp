#include<stdio.h>
#include<stdlib.h>
int main(){
    int M, N;
    while(scanf("%d\t%d", &N, &M)==2){
        if(N==M)
            printf("Yes");
        else if(N>M)
            printf("No");
    }

return 0;
}
