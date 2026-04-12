#include<bits/stdc++.h>
#define fori(x,a,b) for (int x=a;x<=b;x++)
#define int long long
using namespace std;
int n,a[3010];
int f[3010][3010];
 main()
{
   cin>>n;
   fori(i,1,n) cin>>a[i];
   for (int l=n;l>=1;l--)
   {
       fori(r,l,n)
       {
           if (l==r) f[l][r] = a[l];
           else
           {
               f[l][r] = max(a[l] - f[l+1][r],a[r] - f[l][r-1]);
           }
       }
   }
   cout<<f[1][n];
}
