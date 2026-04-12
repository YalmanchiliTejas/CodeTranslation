#include <iostream>

using namespace std;
long long n,i,a[3005],d[3005][3005],k;
int main()
{
   cin>>n;
   for(i=1;i<=n;i++)
   {
       cin>>a[i];
       d[i][i]=a[i];
   }
   for(k=2;k<=n;k++)
   {
       for(i=1;i<=n-k+1;i++)
       {
           d[i][i+k-1] = max(a[i]-d[i+1][i+k-1],a[i+k-1]-d[i][i+k-2]);
       }
   }
   cout<<d[1][n];
    return 0;
}
