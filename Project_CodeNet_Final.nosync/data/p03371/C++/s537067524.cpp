#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
int ai[10005];
#define N 1000000
int main()
{
    int a,b,c,x,y;
    scanf("%d %d %d %d %d",&a,&b,&c,&x,&y);
    int r;
    long long e,s;
    if(x>y)
    {
        r=y;
        e=r*c*2+(x-y)*a;
        s=c*x*2;
    }
    else
    {
        r=x;
        e=r*c*2+(y-x)*b;
        s=y*c*2;
    }
    long long q=x*a,w=b*y;
    if((q+w)>=e&&e<=s)
        printf("%lld\n",e);
    else if((q+w)<e&&(q+w)<s)
        printf("%lld\n",q+w);
    else if(s<(q+w)&&s<e)
        printf("%lld\n",s);
    return 0;
}
