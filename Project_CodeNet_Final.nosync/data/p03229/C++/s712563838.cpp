#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    int n,i;
    cin>>n;
    ll a[n];
    for (i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    ll b[n],c[n],ans1=0,ans2=0;
    if (n&1)
    {
        int ctr=n-1;
        for (i=2;i<n-1;i+=2)
        {
            b[i]=a[ctr];
            ctr--;
        }
        b[n-1]=a[ctr];
        ctr--;
        b[0]=a[ctr];
        for (i=1;i<n;i+=2)
            b[i]=a[(i+1)/2-1];
        for (i=0;i<n-1;i++)
            ans1+=abs(b[i+1]-b[i]);
        ctr=n-1;
        for (i=1;i<n;i+=2)
        {
            c[i]=a[ctr];
            ctr--;
        }
        c[0]=a[ctr];
        ctr--;
        c[n-1]=a[ctr];
        for (i=2;i<n;i+=2)
            c[i]=a[i/2-1];
        for (i=0;i<n-1;i++)
            ans2+=abs(c[i+1]-c[i]);
    }
    else
    {
        int ctr=n-1;
        for (i=2;i<n-1;i+=2)
        {
            b[i]=a[ctr];
            ctr--;
        }
        b[0]=a[ctr];
        for (i=1;i<n;i+=2)
            b[i]=a[(i+1)/2-1];
        for (i=0;i<n-1;i++)
            ans1+=abs(b[i+1]-b[i]);
        ctr=n-1;
        for (i=1;i<n;i+=2)
        {
            c[i]=a[ctr];
            ctr--;
        }
        c[0]=a[ctr];
        for (i=2;i<n;i+=2)
            c[i]=a[i/2-1];
        for (i=0;i<n-1;i++)
            ans2+=abs(c[i+1]-c[i]);
    }
    cout<<max(ans1,ans2)<<endl;
}