#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a ,b,c,x,y,q,w,e,t,p;
    cin>>a>>b>>c>>x>>y;
   if(x>=y)
   {
        q=c*2*y+a*(x-y);
        w=c*2*x;
        e=a*x+b*y;
   }

    else
    {
         q=c*2*x+b*(y-x);
         w=c*2*y;
         e=a*x+b*y;
    }
       t=q>=w?w:q;
       p=t>=e?e:t;
       cout<<p<<endl;

    return 0;
}
