#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
const int N=1000+5;
string str;

int main()
{
    int a,b,c,x,y,sum=0;
    scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
    if(a+b<=2*c)
    {
        sum+=(min(x,y)*(a+b));
        int cc=max(x,y)-min(x,y);
        if(x>y)
        {
            sum+=min(c*2*cc,cc*a);
        }
        else
        {
            sum+=min(c*2*cc,cc*b);
        }
    }
    else
    {
        int dd=min(x,y),cc=max(x,y)-min(x,y);
        sum+=dd*2*c;
        if(x>y)
        {
            sum+=min(c*2*cc,cc*a);
        }
        else
        {
            sum+=min(c*2*cc,cc*b);
        }
    }
    printf("%d\n",sum);
    return 0;
}
