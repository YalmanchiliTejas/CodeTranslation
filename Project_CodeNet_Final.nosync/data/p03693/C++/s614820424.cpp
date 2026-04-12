#include<cstdio>
int main()
{
    int r,g,b;
    while(scanf("%d %d %d",&r,&g,&b)==3)
    {
        int num=r*100+g*10+b;
        if(num%4==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
