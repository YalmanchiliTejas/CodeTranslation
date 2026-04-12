#include<bits/stdc++.h>
using namespace std;
int n,a[200001];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i>0;i-=2)cout<<a[i]<<" ";
    for(int i=(n%2==0?1:2);i<=n-1;i+=2)cout<<a[i]<<" ";
}
