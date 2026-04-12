#include<stdio.h>
int main()
{
    int a,b,c,s;
    while(~scanf("%d %d %d",&a,&b,&c))
    {
        s=a*100+b*10+c;
        if(s%4==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
