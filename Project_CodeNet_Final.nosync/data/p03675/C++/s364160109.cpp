#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
    int n; cin>>n;
    int a[n+5];
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n%2)
    {
        for(int i=n;i>0;i-=2)cout<<a[i]<<" ";
        for(int i=2;i<n;i+=2)cout<<a[i]<<" ";
    }
    else
    {
        for(int i=n;i>0;i-=2)cout<<a[i]<<" ";
        for(int i=1;i<n;i+=2)cout<<a[i]<<" ";
    }
return 0;
}
