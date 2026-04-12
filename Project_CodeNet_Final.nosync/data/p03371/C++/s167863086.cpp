#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,x,y,i;
    long long int s[3],min;
    scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
    if(x>=y)
    {s[0]=x*2*c;
    s[1]=y*2*c+(x-y)*a;
    s[2]=x*a+y*b;
    }
    else
    {s[0]=y*2*c;
    s[1]=x*2*c+(y-x)*b;
    s[2]=x*a+y*b;
    }
    min=s[0];
    for(i=1;i<3;i++)
    {
        if(s[i]<min)
            min=s[i];
    }
    printf("%I64d",min);
    return 0;
}
