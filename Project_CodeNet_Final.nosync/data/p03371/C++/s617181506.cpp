#include<bits/stdc++.h>
using namespace std;
int main()
{
long int a,b,c,x,y,z,k;
  scanf("%ld %ld %ld %ld %ld",&a,&b,&c,&x,&y);
  if(a+b<2*c) printf("%ld",a*x+b*y);
  else 
  {
  if(x<y) {z=x;
          k=y-x;
          if(b<2*c) printf("%ld",2*z*c+b*k);
          else{
           printf("%ld",c*(2*z+2*k));
           }
          }
  else {z=y;
       k=x-y;
        if(a<2*c) printf("%ld",2*z*c+a*k);
          else{
           printf("%ld",c*(2*z+2*k));
       }
  }
return 0;}}