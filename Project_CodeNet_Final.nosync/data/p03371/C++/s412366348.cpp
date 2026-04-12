#include<stdio.h>
int main()
{
    int a,b,c,x,y,m,n,p;
    scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
    if(x>=y)
    {
        m=c*x*2;
        n=c*y*2+a*(x-y);
        p=a*x+b*y;
    }
    if(x<y)
    {
        m=c*y*2;
        n=c*x*2+b*(y-x);
        p=a*x+b*y;
    }
    if(m>n)
        m=n;
    if(m>p)
    m=p;
        printf("%d",m);
    return 0;
}