#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,x,y;
    scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
    if((a+b)>=2*c)
    {
        if(x>=y)
        {
            int ans=c*2*y+(x-y)*a;
            int s=c*2*x;
            ans=min(ans,s);
            printf("%d\n",ans);
        }
        else
        {
            int ans=c*2*x+(y-x)*b;
            int s=c*2*y;
            ans=min(ans,s);
            printf("%d\n",ans);
        }
    }
    else
    {
        int ans=a*x+b*y;
        printf("%d\n",ans);
    }
    return 0;
}
