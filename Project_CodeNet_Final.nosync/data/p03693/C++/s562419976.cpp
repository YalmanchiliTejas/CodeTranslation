#include<stdio.h>

int main()
{
    int a,b,c;
    int flag;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        flag=b*10+c;
        if(flag%4==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
