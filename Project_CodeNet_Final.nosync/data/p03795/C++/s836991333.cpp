#include <stdio.h>
int main()
{
    int a,b;
    scanf("%d",&a);
    if(a<15)
        printf("%d",a*800);
    else
    {
        b=a/15;
        printf("%d",a*800-b*200);
    }
    return 0;
}
