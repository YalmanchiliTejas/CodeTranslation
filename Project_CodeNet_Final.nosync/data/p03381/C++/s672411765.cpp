#include <bits/stdc++.h>

using namespace std;

int a[200005],b[200005];

int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i], b[i]=a[i];
    sort(b,b+n);
    int unu=b[n/2-1];
    int doi=b[n/2];
    for (int i=0;i<n;i++)
    {
        if (a[i]<=unu)
            cout<<doi<<'\n';
        else cout<<unu<<'\n';
    }
    return 0;
}
