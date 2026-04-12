#include<cstdio>
int main()
{
    int r,g,b;
    while(~scanf("%d%d%d",&r,&g,&b))
    {
        int t=r*100+g*10+b;
        printf("%s\n",t%4?"NO":"YES");
    }
    return 0;
}
