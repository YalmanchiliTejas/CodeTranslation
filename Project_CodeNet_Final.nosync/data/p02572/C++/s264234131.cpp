#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    //we are given an array of N integers
    //we have to find out the sum of product of all possible pairs
    //modulo 1000000007
   ll n;
    scanf("%lld",&n);
    vector<ll>a(n);
    ll i,j;
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);

    }

    vector<ll>b;
    j=a[n-1];
    b.push_back(a[n-1]);
    for(i=n-2;i>0;i--)
    {
       j=(a[i]+j);
       //j=j%1000000007;
       b.push_back(j);
    }
    ll s=0;

    for(i=0,j=n-2;i<n-1;i++,j--)
    {
   a[i]=a[i]%1000000007;
   b[j]=b[j]%1000000007;
      a[i]=a[i]*b[j];
      a[i]=a[i]%1000000007;
    }
    for(i=0;i<n-1;i++)
    {
        s+=a[i];

    }
    printf("%lld",s%1000000007);
    return 0;
}