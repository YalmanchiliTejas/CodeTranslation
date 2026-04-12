#include <bits/stdc++.h>
using namespace std;

long long n,a[200005],b[200005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    int l=1,d=n,br=n;
    if(n%2==0)
    {
        while(br)
        {
            b[l]=a[br];
            br--;
            b[d]=a[br];
            br--;
            l++;
            d--;
        }
        for(int i=1;i<=n;i++)
            cout<<b[i]<<" ";
        return 0;
    }
    else
    {
        b[n/2+1]=a[1];
        while(br>1)
        {
            b[l]=a[br];
            br--;
            b[d]=a[br];
            br--;
            l++;
            d--;
        }
        for(int i=1;i<=n;i++)
            cout<<b[i]<<" ";
        return 0;
    }

}
