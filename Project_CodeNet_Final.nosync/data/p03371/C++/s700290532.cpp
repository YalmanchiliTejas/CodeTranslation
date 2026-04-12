#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
    int sum,n,m,p,q,t,a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    sum=1200000000;
    n=a*x+b*y;
   if(x>=y)
   {
      m=2*y*c+(x-y)*a;
   }else m=1200000000;
   if(y>=x)
   {
       p=2*x*c+(y-x)*b;
   }else p=1200000000;
   if(x>=y)
   {
       q=2*c*x;
   }else q=1200000000;
   if(y>=x)
   {
       t=2*c*y;
   }else t=1200000000;
   if(n<sum)
    sum=n;
   if(m<sum)
    sum=m;
   if(p<sum)
    sum=p;
   if(q<sum)
    sum=q;
   if(t<sum)
    sum=t;
    cout<<sum<<endl;
    return 0;
}
