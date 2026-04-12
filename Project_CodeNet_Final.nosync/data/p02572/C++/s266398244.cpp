#include<bits/stdc++.h>
using namespace std;

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long i,j,m,a,b,k,n,w,p,l;
    while(cin>>n)
    {
        long long x[n],sum=0;
        for(i=0; i<n; i++)cin>>x[i];
      //sort(x,x+n);
        for(i=0; i<n; i++)
        {
            sum+=x[i];

        }
        j=0;
        long long ans=0;
        for(i=0; i<n-1; i++)
        {
            sum-=x[i];
       ans+=(((x[i]%1000000007)*(sum%1000000007))%1000000007);
      // cout<<ans<<" ";
        }
        cout<<ans%1000000007<<endl;
    }
    return 0;
}
