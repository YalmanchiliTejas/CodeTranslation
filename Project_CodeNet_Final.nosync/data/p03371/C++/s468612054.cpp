#include<cstdio>
using namespace std;
int main()
{
    int a,b,c,x,y;
    scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
    int sum=0;
    if(c<=(a+b)/2)
    {
        if(x<y)
        {
            sum+=x*2*c;
            sum+=(y-x)*b;
            if(y*2*c<sum)
                sum=y*2*c;
        }
        else
        {
            sum+=y*2*c;
            sum+=(x-y)*a;
            if(x*2*c<sum)
                sum=x*2*c;
        }
    }
    else
    {
        sum+=a*x+b*y;
    }
    printf("%d\n",sum);
    return 0;
}
