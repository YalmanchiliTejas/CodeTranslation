#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
   int n;
   cin>>n;
   ll a[n];ll b[n];
   for(int i=0;i<n;i++)cin>>a[i];
   int k=-1;
   for(int i=0;i<n;i++)
   {
       k++;
       b[k]=a[i];
       while((k>=2)&&(b[k-1]>=b[k-2])&&(b[k-1]>=b[k]))
       {
               b[k-2]=b[k-2]+b[k]-b[k-1];
               k-=2;
       }
   }
   int i=0, j=k, turn=0;
   ll ans=0;
   while(i<=j)
   {
       if(b[i]>=b[j])
       {
         if(!turn)
         {
             ans+=b[i];
             turn=1;
         }
         else
         {
             ans-=b[i];
             turn=0;
         }
         i++;
       }
       else
       {
         if(!turn)
         {
             ans+=b[j];turn=1;
         }
         else
         {
             ans-=b[j];turn=0;
         }
         j--;
       }
   }
   cout<<ans<<endl;
   return 0;
}

