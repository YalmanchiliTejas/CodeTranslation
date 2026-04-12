#include<stdio.h>
int main()
{
    int N,M;
        scanf("%d%d",&N,&M);
        if(N==M)
            printf("Yes\n");
        else if(N>M)
            printf("No\n");
    return 0;
}
