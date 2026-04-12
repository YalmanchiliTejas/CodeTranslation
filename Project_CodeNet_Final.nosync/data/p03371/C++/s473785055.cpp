#include<stdio.h>
int main()
{
    int a, b, c, x, y;
    scanf("%d %d %d %d %d",&a,&b,&c,&x,&y);
    if((a+b)/2<c)
        printf("%d\n", x*a+y*b);
    else if(x<y)
    {
        if(2*c<b) printf("%d\n", 2*y*c);
        else printf("%d\n", 2*x*c+(y-x)*b);
    }
    else
    {
        if(2*c<a) printf("%d\n", 2*x*c);
        else printf("%d\n", 2*y*c+(x-y)*a);
    }
}
