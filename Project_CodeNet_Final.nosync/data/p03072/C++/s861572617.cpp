#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,flag=0;
   long long cnt=0;
   scanf("%d",&n);
   int a[n+1];
   for(int i=0;i<n;i++)scanf("%d",&a[i]);
   for(int i=n-1;i>=0;i--)
   {
       for(int j=i;j>=0;j--)
       {
           if(a[i]>=a[j])flag=1;
           else
           {
               flag=0;
               break;
           }
       }
       if(flag==1)++cnt;
   }
   printf("%lld\n",cnt);
}
