#include <bits/stdc++.h>
using namespace std;

int main()
{
 long a,b,c,x,y,count=0;
 cin>>a>>b>>c>>x>>y;
 if((a+b)>(2*c))
 {
     if(x>y)
     {
         if(a>(2*c))
             count= x*c*2;
          else
          {
              count= y*c*2 + (x-y)*a;
          }
     }
     else
     {
         if(b>(2*c))
             count=y*c*2;
             else
                 count= x*c*2 + (y-x)*b;
     }
    
 }
 else
 {
     count= x*a + y*b;
 }
 cout<<count<<endl;
 return 0;
}