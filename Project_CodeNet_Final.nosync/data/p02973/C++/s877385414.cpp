#include<bits/stdc++.h>
using namespace std;
int n,len,cnt,a[100010],f[100010];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    f[1]=a[1];len=1;
    for(int i=2;i<=n;i++)
        if(f[len]>=a[i])f[++len]=a[i];
        else f[upper_bound(f+1,f+len+1,a[i],greater<int>())-f]=a[i];
    cout<<len;
    return 0;
}