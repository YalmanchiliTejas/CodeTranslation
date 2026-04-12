#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int a[N];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t,i,j,n,m,l,r,s=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=n;i>0;i-=2)
    {
        cout<<a[i]<<" ";
    }
    if(n%2==1)
    {
        i=2;
    }
    else
    {
        i=1;
    }
    for(;i<=n;i+=2)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}

