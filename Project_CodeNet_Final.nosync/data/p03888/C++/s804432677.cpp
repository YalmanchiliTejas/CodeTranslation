#include <stdio.h>

int main(void)
{
    int R1, R2;

    scanf("%d%d",&R1,&R2);

    printf("%f",(double)(R1*R2)/(R1+R2));

    return 0;
}
