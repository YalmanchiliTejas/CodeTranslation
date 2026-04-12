#include<bits/stdc++.h>
using namespace std;
int main()
{
   int a,b,c,x,y,mm[3];
   cin>>a>>b>>c>>x>>y;
    mm[0]=x*a+y*b;
    if(x>y)
    {
       mm[1]=c*2*x;
       mm[2]=c*2*y+(x-y)*a;
    }
    else
    {
       mm[1]=c*2*y;
       mm[2]=c*2*x+(y-x)*b;
    }
    sort(mm,mm+3);
    printf("%d",mm[0]);
    return 0;
}
