#include <bits/stdc++.h>
using namespace std;
long long n,z,x,zx,a[100001],b[100001],c[100001];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    b[1]=a[(n/2)+1], z=1;
    for(int i=1; i<=n/2; i++)
    {
        z++;
        b[z]=a[(n-i)+1];
        z++;
        b[z]=a[i];
    }
    c[1]=a[(n/2)+1], z=1;
    for(int i=1; i<=n/2; i++)
    {
        z++;
        c[z]=a[i];
        z++;
        c[z]=a[(n-i)+1];
    }
    for(int i=1; i<n; i++)
        x+=abs(b[i]-b[i+1]);
    for(int i=1; i<n; i++)
        zx+=abs(c[i]-c[i+1]);
    cout<<max(x,zx)<<endl;
}
