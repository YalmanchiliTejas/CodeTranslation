#include <iostream>

using namespace std;

int main()
{
    int a,b,c,x,y,d;
    int sum1=0,sum2=0,sum3=0;
    cin>>a>>b>>c;
    cin>>x>>y;
    sum1=x*a+y*b;
    int imin=min(x,y)*2;
   // cout<<imin<<endl;
    sum2=imin*c+(y-imin/2)*b+(x-imin/2)*a;
    int imax=max(x,y)*2;
    sum3=imax*c;
    cout<<min(min(sum1,sum2),sum3)<<endl;

}
