#include<iostream>
using namespace std;
#define max(x,y) ((x)>(y)?a:b)
#define vmax(x,y) ((x)>(y)?(x):(y))
int main()
{
int a,b,c,x,y;
cin>>a>>b>>c>>x>>y;
if((c*2)<max(x,y))
{
cout<<(vmax(x,y)*2*c);
return 0;
}
if((c*2)>=(a+b))
{
cout<<(x*a+y*b);
return 0;
}
if(x<y)
{
cout<<(x*2*c+(y-x)*b);
return 0;
}
else
{
cout<<(y*2*c+(x-y)*a);
return 0;
}
}
