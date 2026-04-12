#include<iostream>
using namespace std;
int main()
{
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
   int low,diff;
   int cost=0;
   if(y<x)
   {
       low=y;
       diff=x-y;
   }
   else
   {
         low=x;
         diff=y-x;
   }

    if(a*low+b*low>c*2*low)
    {
        cost+=c*2*low;
    }
    else
        cost+=a*low+b*low;

    if(x>y)
    {
       if(diff*a>c*2*diff)
            cost+=c*2*diff;
       else
           cost+=diff*a;
    }
   else if(y>x)
    {
        if(diff*b>c*2*diff)
            cost+=c*2*diff;
       else
           cost+=diff*b;
    }

    cout<<cost<<endl;
}

