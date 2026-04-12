#include <math.h>
#include <bits/stdc++.h>
#include <deque>
#define ll long long int
#define l long double
#define pi 3.14159265358979323846
#define mod 1000000007
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll a[n],sum=0;
    for(int i=0;i<n;i++)
    cin>>a[i];
    ll b[n];
    for(int i=0;i<n;i++)
    b[i]=0;
    b[0]=a[n-1];
    for(int i=1;i<n;i++)
    b[i]=b[i-1]+a[n-1-i];
    /*for(int i=0;i<n;i++)
    cout<<b[i]<<endl;*/
    for(int i=0;i<n-1;i++)
    {
        sum+=((a[i]%mod)*(b[n-2-i]%mod));
       // cout<<sum<<endl;
       sum=sum%mod;
    }
    cout<<sum<<endl;
}