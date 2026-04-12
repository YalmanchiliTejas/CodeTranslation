#include<bits/stdc++.h>
using namespace std;
int main()
{
      long long int i,j,a,b,c,x,y,r1,r2,s1,s2,z1,z2,m,n;
      int g[3];
      cin>>a>>b>>c>>x>>y;
      if(x==y)
      {
        r1 = a*x; 
        s1 = b*y;
        z1 = r1+s1;
        r2 = c*x*2;
        if(z1>r2)
        {
            cout<<r2<<endl;
        }
        else
            cout<<z1<<endl;
      }
      else
      {
         r1 = a*x;
        s1 = b*y;
        z1 = r1+s1;
        g[0] = z1;
         if(x>y)
         {
             r2 = c*y*2;
             s2 = (x-y)*a;
             z2 = r2+s2;
             g[1]=z2;
             g[2] = c*x*2;
         }
         else
         {
           r2 = c*x*2;
             s2 = (y-x)*b;
             z2 = r2+s2;
             g[1]=z2;
             g[2] = c*y*2;
         }
            sort(g,g+3);
            cout<<g[0]<<endl;
      }

      return 0;
      }
