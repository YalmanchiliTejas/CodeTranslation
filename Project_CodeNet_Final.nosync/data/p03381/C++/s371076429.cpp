#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=2e5+5;

int n;
int a[N], b[N];

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1, b+n+1);
    int mid1=b[n/2];
    int mid2=b[n/2 + 1];
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=mid2)
        {
            cout<<mid1<<endl;
        }
        else
        {
            cout<<mid2<<endl;
        }
    }
    return 0;
}