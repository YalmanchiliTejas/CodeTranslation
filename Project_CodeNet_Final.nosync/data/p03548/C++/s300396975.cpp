#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main(void)
{
     int i,j,k,n,m;
     scanf("%d%d%d",&n,&m,&k);
     for(i=1;i<=100000;i++)
     {
          if(i*m+(i+1)*k>n)
          {
               printf("%d\n",i-1);
               break;
          }
     }
     return 0;
}
