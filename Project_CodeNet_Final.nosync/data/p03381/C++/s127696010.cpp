#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn],b[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i],b[i]=a[i];
    sort(a,a+n);
    int m1=a[n/2-1],m2=a[n/2];
    for(int i=0;i<n;i++)
    {
        if(b[i]<=m1) cout<<m2<<endl;
        else cout<<m1<<endl;
    }
}
