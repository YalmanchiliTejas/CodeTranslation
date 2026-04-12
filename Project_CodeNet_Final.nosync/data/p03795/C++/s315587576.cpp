#include<bits/stdc++.h>
using namespace std;
int main()
{  
   int n,p,r;
   scanf("%d",&n);
   p=n/15;
   n*=800;
   r=n-p*200;
   printf("%d",r);
   return 0;
}