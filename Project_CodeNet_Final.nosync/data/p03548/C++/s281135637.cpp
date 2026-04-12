#include <stdio.h>

int main()
{
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);
    int ans;
    if(x%(y+z)>=z)
    {
        ans=x/(y+z);
    }
    else
    {
        ans=x/(y+z);
        ans--;
    }
    printf("%d\n",ans);
}