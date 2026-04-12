#include<stdio.h>

int main()
{
    int N;
    while(scanf("%d",&N) != EOF)
    {
        if(N >= 15) printf("%d\n",N*800-(N/15)*200);
        else printf("%d\n",N*800);
    }
    return 0;
}
