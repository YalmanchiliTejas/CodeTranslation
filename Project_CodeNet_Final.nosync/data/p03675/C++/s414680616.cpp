#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int b[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    int l=0,r=n-1;
    int cur=n-1;
    while(l<r)
    {
        b[l]=a[cur];
        cur--;
        b[r]=a[cur];
        cur--;
        l++;
        r--;
    }
    if (l==r)
        b[l]=a[cur];
    for (int i=0;i<n;i++)
    {
        cout<<b[i];
        if (i+1<n)
            cout<<' ';
    }
    cout<<endl;
}
