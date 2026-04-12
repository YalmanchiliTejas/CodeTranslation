#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    long long int n,a[200005],i,c,d,sum=0;
    long long int b=1000000007;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    c=a[n-1];
    for(i=n-2;i>=0;i--)
    {
        d=c*a[i];
        d=d%b;
        sum=sum+d;
        sum=sum%b;
        c=c+a[i];
        c=c%b;
    }
    cout<<sum;
}
