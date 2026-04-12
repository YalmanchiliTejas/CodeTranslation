#include <bits/stdc++.h>
using namespace std;

int n,a[200005],b[200005];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=n;i>=1;i-=2)
        cout<<a[i]<<' ';
    if(n%2==0)
        for(int i=1;i<=n;i+=2)
            cout<<a[i]<<' ';
    else
        for(int i=2;i<=n;i+=2)
            cout<<a[i]<<' ';
}
