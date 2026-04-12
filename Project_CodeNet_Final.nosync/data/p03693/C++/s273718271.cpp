#include <cstdio>

int main()
{
    int r,b,g;
    scanf("%d %d %d",&r,&g,&b);
    
    if((r*100 + g*10 + b)%4 == 0)
    {
        printf("YES");
    }
    else 
    {
        printf("NO");
    }
}