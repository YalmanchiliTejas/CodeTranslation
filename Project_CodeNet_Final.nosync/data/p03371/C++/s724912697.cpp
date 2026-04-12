#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long int a,b,c,x,y,sum,sum1,sum2,sum3,sum4,f1,f2;
    cin>>a>>b>>c>>x>>y;
    if(x==y)
    {
        sum1=a*x+b*y;
        sum2=c*x*2;
        sum=min(sum1,sum2);
    }
    if(x<y)
    {
        sum1=a*x+b*y;
        sum2=c*y*2;
        sum3=a*x+b*x+(y-x)*c*2;
        sum4=c*x*2+(y-x)*b;
        f1=min(sum1,sum2);
        f2=min(sum3,sum4);
        sum=min(f1,f2);
    }
     if(y<x)
    {
        sum1=a*x+b*y;
        sum2=c*x*2;
        sum3=a*y+b*y+(x-y)*c*2;
        sum4=c*y*2+(x-y)*a;
        f1=min(sum1,sum2);
        f2=min(sum3,sum4);
        sum=min(f1,f2);
    }
    cout<<sum<<endl;
    return 0;
}
