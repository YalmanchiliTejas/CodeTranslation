# include<bits/stdc++.h>
# include<iostream>
using namespace std;
const long long MAX=1e5+10;
long long a[MAX*2];
long long b[2*MAX];
long long n;
int main ()
{
    cin>>n;
    for(long long i=1; i<=n; i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    int t=b[n/2]+b[n/2+1];
    for(int i=1;i<=n;i++)
    {
        if(a[i]*2<=t)
        {
            cout<<b[n/2+1]<<endl;
        }
        else
            cout<<b[n/2]<<endl;
    }
    return 0;
}
