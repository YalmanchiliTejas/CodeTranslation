#include<bits/stdc++.h>

using namespace std;

const long long maxi=1e16+951;

long long a[1000],b[1000];
long long ans;
int n;
int main()
{
    cin>>n;

    for (int i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);

   for (long long i=1;i<n;i++)
   {
       long long l=0;
       long long r=1e16+1000;

        sort(a+1,a+n+1);
        reverse(a+1,a+n+1);

        if (a[1]<=n*n) break;

        while(l<r-1)
        {
            long long tr=(l+r)/2;
            long long cel=tr/i;

            for (int j=1;j<=n;j++)
                b[j]=a[j];

            for (int j=1;j<=i;j++)
                b[j]-=cel*(n+1-i);

            b[i+1]+=tr;

            for(long long j=1;j<=tr-cel*i;j++)
            {
                sort(b+1,b+i+1);
                reverse(b+1,b+i+1);

                b[1]-=n;
                for (int k=2;k<=i;k++)
                    b[k]++;

            }

               sort(b+1,b+i+1);
               reverse(b+1,b+i+1);

            if (b[i+1]<=b[1]) l=tr; else r=tr;
        }
        ans+=l+1;

        long long cel=(l+1)/i;

            for (int j=1;j<=i;j++)
                a[j]-=cel*(n+1-i);

            for(long long j=1;j<=(l+1)-cel*i;j++)
            {
                sort(a+1,a+i+1);
                reverse(a+1,a+i+1);

                a[1]-=n;
                for (int k=2;k<=i;k++)
                    a[k]++;

            }

        for (int j=i+1;j<=n;j++)
            a[j]+=l+1;
   }



   sort(a+1,a+n+1);
   reverse(a+1,a+n+1);

   ans+=n*max(a[n]-(n-1),0ll);

   for (int i=1;i<=n;i++)
    a[i]-=max(a[n]-(n-1),0ll);

   while(a[1]>=n)
   {
       a[1]-=n;
       for(int i=2;i<=n;i++)
        a[i]++;

       sort(a+1,a+n+1);
       reverse(a+1,a+n+1);
       ans++;
   }
   cout<<ans;
    return 0;
}
