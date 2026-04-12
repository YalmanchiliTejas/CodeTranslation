#include <bits/stdc++.h>

using namespace std;
long long  ans=0;
long long  a[55],b[55];
long long fun(long long n,long long m)
{
    long long ans=0;
    if(n>1)
    {
        if(m>a[n]/2+1 && m!=a[n])
        {
            ans+=b[n-1]+1+fun(n-1,m-a[n]/2-1);
        }
        else if(m==a[n]/2+1)
        {
            ans+=b[n-1]+1;
        }
        else if(m<a[n]/2+1)
        {
            ans+=fun(n-1,m-1);
        }
        else
        {
            ans+=b[n];
        }
    }
    else
    {
        if(m==5)
        {
            ans+=3;
        }
        else if(m>0)
        {
            ans+=m-1;
        }
    }
    return ans;
}
int main()
{
    long long  n,m;
    cin >> n >> m;
    a[0]=b[0]=1;
    for(int i=1; i<=n; i++)
    {
        a[i]=a[i-1]*2+3;
        b[i]=b[i-1]*2+1;
    }
    cout << fun(n,m) << endl;
    return 0;
}
