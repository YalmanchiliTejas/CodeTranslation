#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
   int n, a[1000], i, z=0, m=0;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
       if(a[i]>=m)
       {
           z++;
           m=a[i];
       }
   }
   printf("%d\n",z);
   return 0;
}
