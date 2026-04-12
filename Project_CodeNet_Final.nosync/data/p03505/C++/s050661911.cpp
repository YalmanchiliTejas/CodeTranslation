#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
long long k,a,b;
int main(void)
{
     int i,j,n,m;
     scanf("%lld%lld%lld",&k,&a,&b);
     if(a>=k)
          printf("1\n");
     else
     {
          if(a<=b)
          {
               printf("-1\n");
          }
          else
          {
               /*if(k%(a-b)!=0)
               {
                    printf("%lld\n",k/(a-b)*2+1);
               }
               else
               {
                    if(2*b>=a)
                         printf("%lld\n",k/(a-b)*2-3);
                    else if()
                    else
                         printf("%lld\n",k/(a-b));
               }*/
               long long w=k-a;
               if(w%(a-b)==0)
                    printf("%lld\n",w/(a-b)*2+1);
               else
                    printf("%lld\n",w/(a-b)*2+3);
          }
     }
     return 0;
}
